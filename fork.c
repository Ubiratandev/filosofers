#include "filosofers.h"

void    get_fork(t_filo *filo)
{
    t_table *iot;

    iot = filo->table;
    if(filo->id % 2 == 0)
    {
        pthread_mutex_lock(filo->rigth_fork);
        pthread_mutex_lock(&iot->print);
        printf("printar a pegada do garfo");
        pthread_mutex_unlock(&iot->print);
        pthread_mutex_lock(filo->left_fork);
        printf("printar a pegada do garfo");
        filo->meels--;
        pthread_mutex_unlock(&iot->print);
    }
    else
    {
        pthread_mutex_lock(filo->left_fork);
        pthread_mutex_lock(&iot->print);
        printf("printar que pegou o garfo esquerdo");
        pthread_mutex_unlock(&iot->print);
        pthread_mutex_lock(filo->rigth_fork);
        pthread_mutex_lock(&iot->print);
        printf("printar que pegou o gargo direito");
        filo->meels--;
        pthread_mutex_unlock(&iot->print);
    }
    
 
}