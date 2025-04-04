/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:32:17 by natrodri          #+#    #+#             */
/*   Updated: 2025/03/24 10:32:18 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	clear(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].lock);
		pthread_mutex_destroy(&table->philos[i].meal);
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->dead);
	pthread_mutex_destroy(&table->wait);
	free(table->forks);
	free(table->philos);
}
