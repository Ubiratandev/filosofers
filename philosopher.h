/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-b <uviana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:56:16 by uviana-b          #+#    #+#             */
/*   Updated: 2025/04/04 13:03:16 by uviana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mut_t;
typedef struct timeval	t_timeval;

typedef struct s_philosopher
{
	struct s_table		*table;
	pthread_t			thread;
	int					philo_id;
	int					meals;
	long				last_meal;
	t_mut_t				*left_fork;
	t_mut_t				*right_fork;
	t_mut_t				lock;
	t_mut_t				meal;
}						t_philosopher;

typedef struct s_table
{
	pthread_t			monitor;
	int					philo_num;
	int					tm_sleep;
	int					num_eats;
	int					time_eats;
	int					time_die;
	int					has_dead;
	long				tm_start;
	t_mut_t				*forks;
	t_mut_t				print;
	t_mut_t				dead;
	t_mut_t				wait;
	t_philosopher		*philos;
}						t_table;

long					now(void);
void					*all_eat(void *arg);
int						has_dead(t_table *table);
void					take_fork(t_philosopher *philo);
void					eat(t_philosopher *philo);
void					philo_sleep(t_philosopher *philo);
void					think(t_philosopher *philo);
int						ft_isdigit(int c);
int						ft_atoi(const char *nptr);
long					ft_atol(const char *nptr);
int						starting_thread(t_table *table);
void					clear(t_table *table);
void					*monitor(void *arg);
int						get_meal(t_philosopher *philo);

#endif
