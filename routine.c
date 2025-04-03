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
    
}

void    fil_sleep()
{

}

void    think()
{
    printf("oi");

}