/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-b <uviana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:56 by uviana-b          #+#    #+#             */
/*   Updated: 2025/04/04 12:51:14 by uviana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	has_dead(t_table *table)
{
	int	status;

	pthread_mutex_lock(&table->dead);
	status = table->has_dead;
	pthread_mutex_unlock(&table->dead);
	return (status);
}

void	check_dead(t_philosopher *philo)
{
	long	time;

	pthread_mutex_lock(&philo->table->wait);
	pthread_mutex_lock(&philo->lock);
	time = now() - philo->last_meal;
	pthread_mutex_unlock(&philo->table->wait);
	pthread_mutex_unlock(&philo->lock);
	if (time > philo->table->time_die)
	{
		pthread_mutex_lock(&philo->table->dead);
		printf("%ld %d is died\n", now() - philo->table->tm_start,
			philo->philo_id);
		philo->table->has_dead = 1;
		pthread_mutex_unlock(&philo->table->dead);
	}
}

int	get_meal(t_philosopher *philo)
{
	int	meal;

	meal = 0;
	pthread_mutex_lock(&philo->meal);
	meal = philo->meals;
	pthread_mutex_unlock(&philo->meal);
	return (meal);
}

void	*monitor(void *arg)
{
	int				i;
	t_philosopher	*philo;
	t_table			*t;

	i = 0;
	philo = (t_philosopher *)arg;
	t = philo->table;
	while (!has_dead(t) && get_meal(&t->philos[i]) != t->num_eats)
	{
		check_dead(&philo->table->philos[i]);
		i = (i + 1) % philo->table->philo_num;
		usleep(600);
	}
	return (NULL);
}
