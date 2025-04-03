#include "philosophers.h"

void    phil_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->meel);
    philo->meels--;
    pthread_mutex_unlock(&philo->meel);
    pthread_mutex_lock(&philo->table->print);
    printf("printar que esta comendo \n");
    pthread_mutex_unlock(&philo->table->print);
    pthread_mutex_lock(&philo->lock);
    philo->time_of_last_meel = now();
    pthread_mutex_unlock(&philo->lock);
    usleep(philo->table->time_to_eat * 1000);
    pthread_mutex_unlock(philo->rigth_fork);
    pthread_mutex_unlock(philo->left_fork);


}
void    philo_sleep(t_philo *philo)
{
    t_table *iot;

    iot = philo->table;
    if(!table_is_valid(philo->table))
    {
        pthread_mutex_lock(&iot->print);
        printf("dizer que esta pensando \n");
        pthread_mutex_unlock(&iot->print);
        usleep(iot->time_to_sleep * 1000);
    }
}
void think(t_philo *philo)
{
    long die;
    long eat;
    long sleep;
    t_table *iot;

    die = philo->table->time_to_die;
    eat = philo->table->time_to_eat;
    sleep = philo->table->time_to_sleep;
    iot = philo->table;
    if(!table_is_valid(philo->table))
    {
        pthread_mutex_lock(&iot->print);
        printf("printar que esta pensando \n");
        pthread_mutex_unlock(&iot->print);
        if(die - (eat + sleep) > 10)
            usleep((die - (eat + sleep) * 1000) - 10000);

    }


}

void    phil_sleep(t_philo *philo)
{
    t_table *iot;

    iot = philo->table;
    if(philo->table->valid_table == 0)
    {
        pthread_mutex_lock(&iot->print);
        printf("printar qie esta pensando \n");
        pthread_mutex_unlock(&iot->print);
        usleep(iot->time_to_sleep * 1000);
    }
}
