#include "philosophers.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	num;
	long	op;

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

int ft_is_digit(char *num)
{
    int i;

    i = 0;
    while(num[i])
    {
        if(num[i] >= '0' && num[i] <= '9')
            i++;
        else 
            return(0);
    }
    return(1);
}

int verify_args(char *argv[],int argc)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(i <= argc)
    {
        n = ft_is_digit(argv[i++]);
        if(n == 0)
            return (0);
    }
    return(1);
}

int verify_num_arg(t_table table, char  *argv[], int argc)
{
    if(table.phil_num < 0)
        return(0);
    table.time_to_die = ft_atol(argv[2]) ;
    if(table.time_to_die < 0)
        return(0);
    table.time_to_eat = ft_atol(argv[3]);
    if(table.time_to_eat < 0)
        return(0);
    table.time_to_sleep = ft_atol(argv[4]);
    if(table.time_to_sleep < 0)
        return(0);
    if(argc == 6)
        if(table.max_number_of_eat < 0)
            return(0);
    return(1);
}
//strating_args
int    populate_table(t_table *table, char *argv[],int argc)
{

    if(argc != 5 && argc != 6)
    {
        printf("argument invalid \n");
        return(1);
    }
    if(verify_args(argv, argc))
    {
        return(1);
    }
    table->valid_table = 0;
    table->phil_num = ft_atoi(argv[1]);
    table->time_to_die = ft_atol(argv[2]);
    table->time_to_eat = ft_atol(argv[3]);
    table->time_to_sleep = ft_atol(argv[4]);
    table->max_number_of_eat = -42;
    if(argc == 6)
        table->max_number_of_eat = ft_atoi(argv[5]);
    table->fork = malloc(table->phil_num * sizeof(pthread_mutex_t));
    table->philo = malloc(table->phil_num * sizeof(t_philo));
    return(0);
}

int    thread_init(t_table *table, char *argv[], int argc)
{
    int i;
    t_philo *philo;

    if(initialize_phills(table, argv))
        return(1);
    philo = table->philo;
    i = 0;
    pthread_create(&table->monitor, NULL, monitor, philo);
    populate_table(table, argv,argc);
    while(i < table->phil_num)
    {
    
       pthread_mutex_lock(&table->philo[i].lock);
       table->philo[i].time_of_last_meel = table->time_start;
       pthread_mutex_unlock(&table->philo[i].lock);
       pthread_create(&philo[i].thread, NULL, dinner, &philo[i]);
       //init the diner hereS
        i++;
    }
    i = 0;
    while(i < table->phil_num)
    {
        pthread_join(table->philo[i].thread, NULL);
        i++;
    }
    pthread_join(table->monitor, NULL);
    return(0);
}

int main(int argc, char *argv[])
{
    t_philo philo;
    t_table table;

    table.philo = &philo;
    if(argc < 5 && argc > 6 )
        return(1);
    if(verify_num_arg(table, argv, argc) == 0)
        return(1);
    thread_init(&table, argv, argc);
    destroy_all(&table);
    return(0);
 }
