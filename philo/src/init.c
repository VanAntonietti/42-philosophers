/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:19:07 by vantonie          #+#    #+#             */
/*   Updated: 2022/06/25 15:29:30 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data, t_philo **philo, int argc, char **argv)
{
	if(validation(argc, argv) == 0)
	{
		init_data(data, argc, argv);
		init_philo(data,  philo);
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->n_philo = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if(argc == 6)
		data->times_must_eat = atoi(argv[5]);
}

void	init_philo(t_data *data, t_philo **philo)
{
	int	i;
	philo = malloc(sizeof(t_philo) * data->n_philo);
	i = 0;
	while(i < data->n_philo)
	{
		philo[i]->data = (void *)&data;
		i++;
	}
}