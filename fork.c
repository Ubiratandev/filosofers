#include "filosofers.h"

void    get_fork(t_filo *filo)
{

    int i;
    t_table *iot;

    iot = filo->t_table;
    i = 0;
    pthread_mutex_lock(filo->rigth_fork);
    pthread_mutex_lock(&iot->print);
    printf("printar a pegada do garfo");
    pthread_mutex_unlock(&iot->print);
    pthread_mutex_lock(filo->left_fork);
    printf("printar a pegada do garfo");
    filo->meels--;
    phtread_mutex_unlock(&iot->print);
    
    //chamar a função que come
 
}