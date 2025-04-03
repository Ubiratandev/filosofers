#include "philosophers.h"

long    now(void)
{
    //understand this struct
    t_timeval time;

    gettimeofday(&time, NULL);
    return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    destroy_all(t_table *table)
{  
    int i;

    i = 0;
    while(i < table->phil_num)
    {
        pthread_mutex_destroy(&table->fork[i]);
        pthread_mutex_destroy(&table->philo[i].lock);
        pthread_mutex_destroy(&table->philo[i].meel);
        i++;
    }
    pthread_mutex_destroy(&table->print);
    pthread_mutex_destroy(&table->dead);
    pthread_mutex_destroy(&table->wait_phil_pair_eat);
    free(table->fork);
    free(table->philo);


}