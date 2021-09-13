/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:30:30 by ji-park           #+#    #+#             */
/*   Updated: 2021/09/13 17:36:05 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_or_alive(void *ptr)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo*)ptr;
	info = philo->info;
	while (TRUE)
	{
		if (info->all_alive == FALSE ||
		philo->eat_nums == philo->info->minimul_eat)
			break ;
		pthread_mutex_lock(&info->first_die);
		if (get_ms_time() - philo->last_eat > info->time_to_die)
		{
			info->all_alive = FALSE;
			pthread_mutex_unlock(&info->fork[philo->r_fork]);
			print_state(philo, DIE);
			return (NULL);
		}
		pthread_mutex_unlock(&info->first_die);
		usleep(20);
	}
	return (NULL);
}

void	print_state(t_philo *philo, int state)
{
	unsigned long	now;
	t_info			*info;

	pthread_mutex_lock(&philo->info->print_state);
	now = get_ms_time() - philo->info->start_time;
	info = philo->info;
	if (info->all_alive == TRUE && state == FORK)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_FORK);
	else if (info->all_alive == TRUE && state == EAT)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_EAT);
	else if (info->all_alive == TRUE && state == SLEEP)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_SLEEP);
	else if (info->all_alive == TRUE && state == THINK)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_THINK);
	else if (state == DIE)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_DIE);
	pthread_mutex_unlock(&(philo->info->print_state));
}

void	philo_eat_or_sleep(unsigned long time)
{
	unsigned long end;

	end = get_ms_time() + time;
	while (end > get_ms_time())
		usleep(100);
}

void	pickup_forks_to_eat(t_philo *philo)
{
	t_info *info;

	info = philo->info;
	if ((philo->id % 2 == 0 && !pthread_mutex_lock(&info->fork[philo->l_fork]))
	|| !pthread_mutex_lock(&info->fork[philo->r_fork]))
		print_state(philo, FORK);
	if ((philo->id % 2 == 0 && !pthread_mutex_lock(&info->fork[philo->r_fork]))
	|| !pthread_mutex_lock(&info->fork[philo->l_fork]))
		print_state(philo, FORK);
	philo->last_eat = get_ms_time();
	print_state(philo, EAT);
	philo_eat_or_sleep(info->time_to_eat);
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
	philo->eat_nums++;
}

void	*do_routine(void *ptr)
{
	t_info		*info;
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo*)ptr;
	info = philo->info;
	pthread_create(&monitor, NULL, dead_or_alive, philo);
	while (TRUE)
	{
		if (info->all_alive == FALSE)
			break ;
		pickup_forks_to_eat(philo);
		if (info->minimul_eat != -1 &&
		info->minimul_eat == philo->eat_nums)
			break ;
		print_state(philo, SLEEP);
		philo_eat_or_sleep(info->time_to_sleep);
		print_state(philo, THINK);
	}
	pthread_join(monitor, NULL);
	return (NULL);
}
