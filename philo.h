/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:32:07 by natrodri          #+#    #+#             */
/*   Updated: 2025/03/24 10:32:08 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mtx;
typedef struct timeval	t_timeval;

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		thread;
	int				id;
	int				meals;
	long			last_meal;
	t_mtx			*left_fork;
	t_mtx			*right_fork;
	t_mtx			lock;
	t_mtx			meal;
}	t_philo;

typedef struct s_table
{
	pthread_t	monitor;
	int			philo_nbr;
	int			tm_sleep;
	int			num_eats;
	int			time_eats;
	int			time_die;
	int			has_dead;
	long		tm_start;
	t_mtx		*forks;
	t_mtx		print;
	t_mtx		dead;
	t_mtx		wait;
	t_philo		*philos;
}	t_table;

long	now(void);
void	*dinner(void *arg);
int		has_dead(t_table *table);
void	take_fork(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		starting_thread(t_table *table);
void	clear(t_table *table);
void	*monitor(void *arg);
int		get_meal(t_philo *philo);

#endif
