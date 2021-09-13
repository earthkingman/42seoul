/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:30:35 by ji-park           #+#    #+#             */
/*   Updated: 2021/09/13 17:31:28 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			free_philos(t_philo *philos)
{
	int		i;
	t_info	*info;

	i = -1;
	info = philos->info;
	while (++i < info->philo_nums)
		pthread_mutex_destroy(&info->fork[i]);
	pthread_mutex_destroy(&info->print_state);
	pthread_mutex_destroy(&info->first_die);
	free(info->fork);
	free(philos);
}

void			philo_thread_init(t_philo *philos, t_info *info)
{
	int i;

	i = 0;
	while (i < info->philo_nums)
	{
		philos[i].id = i + 1;
		philos[i].r_fork = i;
		if (i == 0)
			philos[i].l_fork = info->philo_nums - 1;
		else
			philos[i].l_fork = i - 1;
		philos[i].eat_nums = 0;
		philos[i].last_eat = get_ms_time();
		philos[i].info = info;
		pthread_create(&philos[i].thread, NULL, do_routine, &philos[i]);
		i++;
	}
	i = -1;
	while (++i < info->philo_nums)
		pthread_join(philos[i].thread, NULL);
}
