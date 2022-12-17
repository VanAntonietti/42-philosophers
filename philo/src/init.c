#include "philo.h"

void	init(t_data *data, int argc, char **argv)
{
	if(validation(argc, argv) == 0)
	{
		init_data(data, argc, argv);
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
}