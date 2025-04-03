#include "filosofers.h"



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

int verify_args(char *argv[])
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(i <= 5)
    {
        n = ft_is_digit(argv[i++]);
        if(n == 0)
            return (0);
    }
    return(1);
}

int verify_num_arg(t_table table, char  *argv[], int argc)
{
    if(table.fil_num < 0)
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

void    populate(t_table *table, char *argv[],int argc)
{
    if(verify_args(argv) == 1)
    {
        return;
    }
    table->fil_num = ft_atoi(argv[1]);
    table->time_to_die = ft_atol(argv[2]);
    table->time_to_eat = ft_atol(argv[3]);
    table->time_to_sleep = ft_atol(argv[4]);
    table->max_number_of_eat = -42;
    if(argc == 6)
        table->max_number_of_eat = ft_atoi(argv[5]);
    table->fork = malloc(table->fil_num * sizeof(pthread_mutex_t));
    table->filo = malloc(table->fil_num * sizeof(t_filo));
}

void    *count_at_100(void *ptr)
{
    t_filo *filo;

    filo  =  (t_filo *)ptr;
    int i;

    i = 0;
    while(i <= 10)
    {
        filo->remover_depois = i;
        i++;
        printf("%d \n", filo->remover_depois);
    }
    return (NULL);
}

void    tread_init(t_table *table, char *argv[], int argc)
{
    int i;

    i = 0;
    populate(table, argv,argc);
    while(i < table->fil_num)
    {
    
       pthread_mutex_lock(&table->filo[i].lock);
       table->filo[i].time_of_last_meel = table->time_start;
       pthread_mutex_unlock(&table->filo[i].lock);
       pthread_create(&table->filo[i].tread, NULL, count_at_100, &table->filo[i]);
        i++;
    }
    i = 0;
    while(i < table->fil_num)
    {
        pthread_join(table->filo[i].tread, NULL);
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_filo filo;
    t_table table;

    table.filo = &filo;
    if(argc < 5 && argc > 6 )
        return(1);
    if(verify_num_arg(table, argv, argc) == 0)
        return(1);
    tread_init(&table, argv, argc);
 }
