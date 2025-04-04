/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-b <uviana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:50:16 by uviana-b          #+#    #+#             */
/*   Updated: 2025/04/04 12:51:20 by uviana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_mutex(t_table *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_num)
	{
		if (pthread_mutex_init(&t->forks[i], NULL))
		{
			printf("Error: mutex init\n");
			return (1);
		}
	}
	if (pthread_mutex_init(&t->print, NULL) || pthread_mutex_init(&t->dead,
			NULL) || pthread_mutex_init(&t->wait, NULL))
	{
		printf("Error: mutex init\n");
		return (1);
	}
	return (0);
}

int	init_philos(t_table *table)
{
	int	i;

	if (!table->philos || !table->forks)
	{
		printf("malloc error\n");
		return (1);
	}
	if (init_mutex(table))
		return (1);
	i = -1;
	while (++i < table->philo_num)
	{
		table->philos[i].philo_id = i;
		table->philos[i].meals = 0;
		table->philos[i].last_meal = now();
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_num];
		table->philos[i].table = table;
		pthread_mutex_init(&table->philos[i].lock, NULL);
		pthread_mutex_init(&table->philos[i].meal, NULL);
	}
	return (0);
}

int	starting_thread(t_table *table)
{
	int				i;
	t_philosopher	*philos;

	if (init_philos(table))
		return (1);
	i = -1;
	philos = table->philos;
	table->tm_start = now();
	pthread_create(&table->monitor, NULL, monitor, philos);
	while (++i < table->philo_num)
	{
		pthread_mutex_lock(&table->philos[i].lock);
		philos[i].last_meal = table->tm_start;
		pthread_mutex_unlock(&table->philos[i].lock);
		pthread_create(&philos[i].thread, NULL, all_eat, &philos[i]);
	}
	i = -1;
	while (++i < table->philo_num)
		pthread_join(philos[i].thread, NULL);
	pthread_join(table->monitor, NULL);
	return (0);
}
