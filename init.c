#include "filosofers.h"

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

void    init_mutex(t_table *table,int num_of_fill)
{
    int i;

    i = 0;
    while(i < num_of_fill)
        pthread_mutex_init(&table->fork[i],NULL);
    pthread_mutex_init(&table->print, NULL);
    pthread_mutex_init(&table->dead, NULL);
    pthread_mutex_init(&table->wait_fil_pair_eat, NULL);
}

void    initialize_fills(int num_of_fill, t_filo *filo, t_table *table, char *argv[])
{
    int i;

    i = 0;
    init_mutex(table,num_of_fill);
    while(i <= num_of_fill)
    {
        filo[i].id = i;
        filo[i].meels = ft_atoi(argv[3]);
        filo[i].left_fork = &table->fork[i];
        filo[i].rigth_fork = &table->fork[(i + 1) % num_of_fill];
        filo[i].table = table;
        pthread_mutex_init(&table->filo[i].meel, NULL);
        pthread_mutex_init(&table->filo[i].lock, NULL);
    }
}
