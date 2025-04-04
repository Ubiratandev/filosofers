

#include "philosopher.h"

void	first_eat(t_philosopher *philo)
{
	long	start;

	start = philo->table->tm_start;
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", now() - start, philo->philo_id);
	pthread_mutex_unlock(philo->left_fork);
}

void	*all_eat(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->table->philo_num == 1)
	{
		first_eat (philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
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

void	take_fork(t_philosopher *philo)
{
	t_table	*t;

	t = philo->table;
	if (philo->philo_id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->philo_id + 1);
		pthread_mutex_unlock(&t->print);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->philo_id + 1);
		pthread_mutex_unlock(&t->print);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->philo_id + 1);
		pthread_mutex_unlock(&t->print);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&t->print);
		printf("%ld %d has taken a fork\n", now() - t->tm_start, philo->philo_id + 1);
		pthread_mutex_unlock(&t->print);
	}
}
