#include "filosofers.h"

int ft_is_digit(char *num)
{
    int i;

    i = 0;
    while(num[i])
    {
        if(num[i] >= '0' && num[i] <= '9')
            i++;
        else 
            return(0);
    }
    return(1);
}
int verify_args(char *argv[])
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(i <= 5)
    {
        n = ft_is_digit(argv[i++]);
        if(n == 0)
            return (0);
    }
    return(1);
}
int verify_num_arg(t_table table, int argc)
{
    if(table.fil_num < 0)
        return(0);
    if(table.time_to_die = ft_atol(argv[2]) < 0)
        return(0);
    if(table.time_to_eat = ft_atol(argv[3])< 0)
        return(0);
    if(table.time_to_sleep = ft_atol(argv[4]) < 0)
        return(0);
    if(argc == 6)
        if(table.max_number_of_eat < 0)
            return(0);
    return(1);
}
void    populate(t_filo filo,t_table table, ing argc)
{
    if(verify_args(argv) == 0)
        return(1);
    table.fil_num = ft_atoi(argv[1]);
    table.time_to_die = ft_atol(argv[2]);
    table.time_to_eat = ft_atol(argv[3]);
    table.time_to_sleep = ft_atol(argv[4])
    table.max_number_of_eat = -42;
    if(argc = 6)
        table.max_number_of_eat[argv[5]];
    table.fork = malloc(table.fil_num * sizeof pthread_mutex_t);
    table.filo = malloc(table.fil_num * sizeof t_filo);
}
//todo criar a função que checa os maloc da table
void    init_mutex(t_table table,int num_of_fill)
{
    int i;

    i = 0
    while(i < num_of_fill)
        pthread_mutex_init(table.fork[i],NULL);
    //verificar a alocação de memoria
    pthread_mutex_init(table.print, NULL);
    pthread_mutex_init(table.dead, NULL);
    pthread_mutex_init(table.wait_fil_pair_eat, NULL);
}
void    initialize_fills(int num_of_fill, t_filo filo, t_table table)
{
    int i;

    i = 0;
    //charmar a função que inicializa os mutex
    init_mutex(table,num_of_fill)
    while(i <= num_of_fill)
    {
        filo.id = i;
        filo.meels = 0;
        filo.left_fork = table.fork[i];
        filo.rigth_fork = table.fork[(i + 1) % num_of_fill];
        filo.table = table;
        pthread_mutex_init(filo.meel, NULL);
        pthread_mutex_init(filo.look, NULL);
    }
}
void    count_at_100(void *ptr)
{
    t_filo *filo;

    filo  =  (t_filo *)ptr;
    int i;

    i = 0;
    while(i <= 10)
    {
        filo.remover_depois = i;
        i++;
        printf("%d", filo.remover_depois);
    }
}
void    tread_init(t_table *table)
{
    int i;

    i = 0;
    while(i < table.fil_num)
    {
       pthread_mutex_lock(&table->filo[i].lock);
       table->filo[i].time_if_last_meel = table.time_start;
       pthread_mutex_unlock(&table->filo[i].lock);
       pthread_create(table->filo[i].thread, NULL, count_at_100, &table->filo[i]);
        i++;
    }
    i = 0;
    while(i < table.fil_num)
    {
        pthread_join(table->filo[i].thread, NULL);
        i++;
    }
}
int main(int argc, char *argv[])
{
    //receber 4 parametros
    t_filo filo;
    t_table table;
    int num_of_fill;

    if(argc < 5 && argc > 6 )
        return(1);
    populate(filo,table,argc);
    //ver se todos sao positivos
    if(verify_num_arg(t_filo filo, argc) == 0)
        return(1);
    num_of_fill = table.fill_num;
    //instanciar os filosofos em uma lista circular ou não
    //converter para medida de tempo correta de nanosegundos para microsegundos sys/time.h get_time_of_days
    //inciar as treads atribuir id, ultima_refeição, 
    //a mesa tem a quanto tempo a simulaãp começou e uma tread para monitorar se os filosofos estao vivod
    //criar as 4 funcloes pensar dormir comer e monitorar a vida

}