#include "filosofers.h"

void    fil_eat(t_filo *filo)
{
    pthread_mutex_lock(&filo->meal);
    filo->meals--;
    pthread_mutex_unlock(&filo->meal);
    pthread_mutex_lock(&filo->table.print);
    printf("printar que esta comendo");
    pthread_mutex_unlock(&filo->table.print);
    pthread_mutex_lock(&filo->lock);
    filo->time_of_last_meel = now();
    pthread_mutex_unlock(&filo->lock);
    usleep(filo->table->time_to_eat * 1000);
    pthread_mutex_unlock(filo->rigth_fork);
    pthread_mutex_unlock(filo->left_fork);


}
void    filo_sleep(t_filo *filo)
{
    t_table *iot;

    iot = filo->table;
    if(iot->valid_table == 0)
    {
        pthread_mutex_lock(&iot->print);
        print("dizer que esta pensando");
        pthread_mutex_unlock(&iot->print);
        usleep(iot->time_to_sleep * 1000);
    }
}
void think(t_filo *filo)
{
    long die;
    long eat;
    long sleep;
    t_table *iot;

    die = filo->table->time_to_die;
    eat = filo->table->time_to_eat;
    sleep = filo->table->time_to_sleep;
    iot = filo->table;
    if(filo->table->valid_table == 0)
    {
        phtread_mutex_lock(iot->print);
        printf("printar que esta pensando");
        phtriead_mutex_unlock(iot->print);
        if(die - (eat + sleep) > 10)
            usleep((die - (eat + sleep) * 1000) - 10000);

    }


}

void    fil_sleep(t_filo *filo)
{
    t_table *iot;

    iot = filo->table;
    if(filo->table.valid_table == 0)
    {
        pthread_mutex_lock(iot->print);
        printf("printar qie esta pensando");
        pthread_mutex_unlock(iot->print);
        usleep(filo->time_to_sleep * 1000);
    }
}
