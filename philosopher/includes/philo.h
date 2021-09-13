/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:30:43 by ji-park           #+#    #+#             */
/*   Updated: 2021/09/13 17:35:57 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE		1
# define FALSE		0
# define FORK		2
# define EAT		3
# define SLEEP		4
# define THINK		5
# define DIE		6

# define S_FORK		"\e[32mhas taken a fork\e[39m\n"
# define S_EAT		"\e[33mis eating\e[39m\n"
# define S_SLEEP	"\e[96mis sleeping\e[39m\n"
# define S_THINK	"\e[0;35mis thinking\e[39m\n"
# define S_DIE		"\033[0;31mdied\e[39m\n"

typedef struct		s_info
{
	int				philo_nums;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	long			time_to_sleep;
	int				minimul_eat;
	unsigned long	start_time;
	int				all_alive;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_state;
	pthread_mutex_t first_die;
}					t_info;

typedef struct		s_philo
{
	int				id;
	int				r_fork;
	int				l_fork;
	int				eat_nums;
	unsigned long	last_eat;
	pthread_t		thread;
	t_info			*info;
}					t_philo;

int					ft_atoi(const char *s);
int					ft_isdigit(int c);

/**utils.c**/
void				free_philos(t_philo *philos);
void				philo_thread_init(t_philo *philos, t_info *info);

/**routine.c**/
void				*dead_or_alive(void *ptr);
void				print_state(t_philo *philo, int state);
void				philo_eat_or_sleep(unsigned long time);
void				pickup_forks_to_eat(t_philo *philo);
void				*do_routine(void *ptr);

/**main.c**/
int					error_exit(char *str);
unsigned long		get_ms_time(void);
int					fill_info(int ac, char **av, t_info *info);
int					philo_mutex_malloc(t_philo **philos, t_info *info);

#endif
