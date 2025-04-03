#include "philosophers.h"

void    initial_dinning(t_philo *philo)
{
    long    start;

    start = philo->table->time_start;
    pthread_mutex_lock(philo->left_fork);
    printf("%ld printar que o phill pegou o garfo", start);
    pthread_mutex_unlock(philo->left_fork);
    
}
void    *dinner(void *arg_philo)
{
    t_philo  *philo;

    philo = (t_philo *)arg_philo;
    if(philo->table->phil_num == 1)
    {
        initial_dinning(philo);
        return(NULL);
    }
    if(philo->table->phil_num % 2 == 0)
    {
        usleep(600);
    }
    while(!table_is_valid(philo->table) 
        && get_meal(philo) == philo->table->max_number_of_eat)
    {
        get_fork(philo);
        phil_eat(philo);
        phil_sleep(philo);
    }
    return(NULL);

}