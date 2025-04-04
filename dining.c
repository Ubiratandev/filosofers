/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:31:24 by natrodri          #+#    #+#             */
/*   Updated: 2025/03/24 10:31:25 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dinner_one(t_philo *philo)
{
	long	start;

	start = philo->table->tm_start;
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", now() - start, philo->id);
	pthread_mutex_unlock(philo->left_fork);
}

void	*dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->philo_nbr == 1)
	{
		dinner_one (philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(600);
	while (!has_dead(philo->table) && get_meal(philo) != philo->table->num_eats)
	{
		take_fork(philo);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}
