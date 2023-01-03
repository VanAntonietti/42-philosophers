/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:44 by vantonie          #+#    #+#             */
/*   Updated: 2023/01/03 16:04:11 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data, int argc, char **argv)
{
	t_philo	*philo;

	init_data(data, argc, argv);
	if (validation(data) == 0)
	{
		philo = init_philo(data);
		start_philo(philo);
	}
	else
	{
		printf("Error\n");
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->s_argc = argc;
	data->s_argv = argv;
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else
		data->times_must_eat = -1;
	data->dead = 0;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->lock_print, NULL);
}
