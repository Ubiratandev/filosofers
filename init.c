#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	op;

	i = 0;
	num = 0;
	op = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			op *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * op);
}

int   init_mutex(t_table *table,int num_of_phill)
{
    int i;

    i = 0;
    while(i < num_of_phill)
        pthread_mutex_init(&table->fork[i],NULL);
    pthread_mutex_init(&table->print, NULL);
    pthread_mutex_init(&table->dead, NULL);
    pthread_mutex_init(&table->wait_phil_pair_eat, NULL);
	return(0);
}

int   initialize_phills(t_table *table, char *argv[])
{
    int i;
	t_philo *philo;

	philo = table->philo;

	if(!table->philo || !table->fork)
	{
		(printf("malloc error /n"));
		return(1);
	}
	if(init_mutex(table, table->phil_num))
	return(1);
    i = 0;
    while(i <= table->phil_num)
    {
        philo[i].id = i;
        philo[i].meels = ft_atoi(argv[3]);
        philo[i].left_fork = &table->fork[i];
        philo[i].rigth_fork = &table->fork[(i + 1) % table->phil_num];
        philo[i].table = table;
        philo[i].time_of_last_meel = now();

        pthread_mutex_init(&table->philo[i].meel, NULL);
        pthread_mutex_init(&table->philo[i].lock, NULL);
    }
	return(0);
}
