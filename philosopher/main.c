/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:30:18 by ji-park           #+#    #+#             */
/*   Updated: 2021/09/13 17:30:20 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				error_exit(char *str)
{
	printf("%s", str);
	return (0);
}

unsigned long	get_ms_time(void)
{
	struct timeval	tmp;
	unsigned long	miliseconds;

	gettimeofday(&tmp, NULL);
	miliseconds = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	return (miliseconds);
}

int				fill_info(int ac, char **av, t_info *info)
{
	if ((!ft_isdigit(*(av[1])) || !ft_isdigit(*(av[2])) || !ft_isdigit(*(av[3]))
	|| !ft_isdigit(*(av[4]))) || (ac == 6 && !ft_isdigit(*(av[5]))))
		return (0);
	info->philo_nums = ft_atoi(av[1]); // 철학자수
	info->time_to_die = ft_atoi(av[2]); // 굶으면 죽는 시간
	info->time_to_eat = ft_atoi(av[3]); // 밥을 먹는 시간
	info->time_to_sleep = ft_atoi(av[4]); //자는 시간
	info->minimul_eat = -1;//인자가 5개 들어오지 않았을 때를 고려해 우선 -1 채움
	if (ac == 6)
		info->minimul_eat = ft_atoi(av[5]); // 각자 스파게티를 먹는 시간
	if ((info->philo_nums < 0 || info->time_to_die < 0 ||
	info->time_to_eat < 0 || info->time_to_sleep < 0) ||
	(ac == 6 && info->minimul_eat < 0))
		return (0);
	info->start_time = get_ms_time(); // 현재시간 받아오기
	info->all_alive = TRUE; // 모두가 살아있다.
	return (1);
}

int				philo_mutex_malloc(t_philo **philos, t_info *info)
{
	int i;
	// 포크 수마큼 사람수 생성
	*philos = (t_philo*)malloc(sizeof(t_philo) * info->philo_nums);
	if (*philos == 0)
		return (0);
	// 포크 인자값만큼 생성
	info->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
			* info->philo_nums);
	if (info->fork == 0)
	{
		free(*philos);
		return (0);
	}
	i = -1;
	while (++i < info->philo_nums)
		pthread_mutex_init(&info->fork[i], NULL);//뮤텍스 초기화
	pthread_mutex_init(&info->print_state, NULL);//초기화 안 해주면 lock(), unlock()이 제기능 못함
	pthread_mutex_init(&info->first_die, NULL);
	return (1);
}

int				main(int ac, char **av)
{
	t_info	info;
	t_philo	*philos;

	if (ac < 4 || ac > 6)
		return (error_exit("\e[31mError: wrong number of \
		arguments!\e[0m\n"));
	if (fill_info(ac, av, &info) == 0)
		return (error_exit("\e[31mError: invalid arguments!\e[0m\n"));
	philos = 0;
	if (philo_mutex_malloc(&philos, &info) == 0)//철학자 수만큼 철학자 구조체와 뮤텍스 할당
		return (error_exit("\e[31mError: out of memory \
		allocation!\e[0m\n"));
	philo_thread_init(philos, &info);
	free_philos(philos);
	return (0);
}
