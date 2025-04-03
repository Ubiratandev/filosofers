#include "philosophers.h"

void    get_fork(t_philo *philo)
{
    t_table *iot;

    iot = philo->table;
    if(philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->rigth_fork);
        pthread_mutex_lock(&iot->print);
        printf("printar a pegada do garfo \n");
        pthread_mutex_unlock(&iot->print);
        pthread_mutex_lock(philo->left_fork);
        printf("printar a pegada do garfo\n");
        philo->meels--;
        pthread_mutex_unlock(&iot->print);
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(&iot->print);
        printf("printar que pegou o garfo esquerdo \n");
        pthread_mutex_unlock(&iot->print);
        pthread_mutex_lock(philo->rigth_fork);
        pthread_mutex_lock(&iot->print);
        printf("printar que pegou o gargo direito \n");
        philo->meels--;
        pthread_mutex_unlock(&iot->print);
    }
    

}