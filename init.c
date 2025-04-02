#include "filosofers.h"

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
