#ifndef FILOSOFERS_H
 #define FILOSOFERS_H
    #include <stdio.h>
    #include <pthread.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <stdlib.h>
    typedef struct timeval t_timeval;
    
    typedef struct s_filo{
        int id;
        int meels;
        long    time_of_last_meel;
        pthread_mutex_t  *left_fork;
        pthread_mutex_t  *rigth_fork;
        pthread_mutex_t  lock;
        pthread_mutex_t  meel;
        pthread_t    tread;
        // struct  t_table *table;
        int remover_depois;
        struct s_table	*table;
    }t_filo;
    
    typedef struct s_table
    {
        int             fil_num;
        long            time_to_eat;
        long            time_to_sleep;
        long            time_to_die;
        int             max_number_of_eat;
        long            time_start;
        pthread_mutex_t  *fork;
        pthread_mutex_t  print;
        pthread_mutex_t  dead;
        pthread_mutex_t  wait_fil_pair_eat;
        pthread_t  monitor;
        int valid_table;
        t_filo          *filo;
    }t_table;
    int	ft_atoi(const char *nptr);
    long	ft_atol(const char *nptr);
    int ft_is_digit(char *num);
    int verify_args(char *argv[]);
    int verify_num_arg(t_table table, char  *argv[], int argc);
    void    populate(t_table *table, char *argv[],int argc);
    void    *count_at_100(void *ptr);
    void    tread_init(t_table *table, char *argv[], int argc);
    void    init_mutex(t_table *table,int num_of_fill);
    void    initialize_fills(int num_of_fill, t_filo *filo, t_table *table, char *argv[]);










#endif