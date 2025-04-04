

#include "philo.h"

void	take_fork(t_philo *philo)
{
	t_table	*t;

	t = philo->table;
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->id + 1);
		pthread_mutex_unlock(&t->print);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->id + 1);
		pthread_mutex_unlock(&t->print);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->id + 1);
		pthread_mutex_unlock(&t->print);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->id + 1);
		pthread_mutex_unlock(&t->print);
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->meal);
	pthread_mutex_lock(&philo->table->print);
	printf("%ld %d is eating\n", now() - philo->table->tm_start, philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = now();
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->table->time_eats * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	t_table	*t;

	t = philo->table;
	if (!has_dead(philo->table))
	{
		pthread_mutex_lock(&t->print);
		printf("%ld %d is sleeping\n", now() - t->tm_start, philo->id + 1);
		pthread_mutex_unlock(&t->print);
		usleep(t->tm_sleep * 1000);
	}
}

void	think(t_philo *philo)
{
	long	die;
	long	eat;
	long	sleep;
	t_table	*t;

	die = philo->table->time_die;
	eat = philo->table->time_eats;
	sleep = philo->table->tm_sleep;
	t = philo->table;
	if (!has_dead(philo->table))
	{
		pthread_mutex_lock(&t->print);
		printf("%ld %d is thinking\n", now() - t->tm_start, philo->id + 1);
		pthread_mutex_unlock(&t->print);
		if (die - (eat + sleep) > 10)
			usleep(((die - (eat + sleep)) * 1000) - 10000);
	}
}
