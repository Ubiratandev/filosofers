#include "philosophers.h"

int    table_is_valid(t_table *table)
{
    int status;

    pthread_mutex_lock(&table->dead);
    status =  table->valid_table;
    pthread_mutex_unlock(&table->dead);
    return(status);

}

void    check_dead(t_philo *philo)
{
    long    time;

    pthread_mutex_lock(&philo->table->wait_phil_pair_eat);
    pthread_mutex_lock(&philo->lock);
    time = now() - philo->time_of_last_meel;
    pthread_mutex_unlock(&philo->table->wait_phil_pair_eat);
    pthread_mutex_unlock(&philo->lock);
    if(time > philo->table->time_to_die)
    {
        pthread_mutex_lock(&philo->table->dead);
        pthread_mutex_lock(&philo->table->print);
        printf("printar que o philosofo morreu \n");
        philo->table->valid_table = 1;
        pthread_mutex_unlock(&philo->table->dead);
        pthread_mutex_unlock(&philo->table->print);
    }


}

int   get_meal(t_philo *philo)
{
    int meal;

    meal = 0;
    pthread_mutex_lock(&philo->meel);
    meal = philo->meels;
    pthread_mutex_unlock(&philo->meel);
    return(meal);
}

void    *monitor(void *arg)
{
    int i;
    t_philo *iof;
    t_table *iot;

    i = 0;
    iof = (t_philo *)arg;
    iot = iof->table;
    while(!table_is_valid(iot) && get_meal(&iof[i]) != iot->max_number_of_eat)
    {
        check_dead(&iof->table->philo[i]);
        i = (i + 1) % iof->table->phil_num;
    } 
    return (NULL);
}
