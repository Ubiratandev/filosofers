
#include "philosopher.h"

int	check_args(char *av)
{
	int	i;

	i = 0;
	if (ft_atol(av) <= 0)
	{
		printf("argument cannot be zero");
		return (1);
	}
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0)
		{
			printf("the argument must only contain numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_table(int ac, char **av, t_table *table)
{
	int	i;

	i = 0;
	if (ac != 5 && ac != 6)
	{
		printf ("argument invalid'\n");
		return (1);
	}
	while (++i < ac)
	{
		if (check_args(av[i]))
			return (1);
	}
	table->has_dead = 0;
	table->num_eats = -42;
	table->philo_num = ft_atoi(av[1]);
	table->time_die = ft_atol(av[2]);
	table->time_eats = ft_atol(av[3]);
	table->tm_sleep = ft_atol(av[4]);
	if (ac == 6)
		table->num_eats = ft_atoi(av[5]);
	table->forks = malloc(table->philo_num * sizeof(p_mut_t));
	table->philos = malloc(table->philo_num * sizeof(t_philosopher));
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (init_table(ac, av, &table))
		return (1);
	if (starting_thread(&table))
		return (1);
	clear(&table);
	return (0);
}
