/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:46 by vantonie          #+#    #+#             */
/*   Updated: 2023/01/02 15:20:33 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	t_mutex *fork;
	int		i;
	
	philo = malloc(data->n_philo * sizeof(t_philo));
	fork = malloc(data->n_philo * sizeof(t_mutex));
	i = -1;
	while (++i < data->n_philo)
	{
		philo[i].data = data;
		philo[i].id = i;
		philo[i].last_meal = 0;
		philo[i].fork = malloc(2 * sizeof(t_mutex));
		philo[i].fork[0] = fork[i];
		philo[i].fork[1] = fork[(i + 1) % data->n_philo];
		philo[i].times_ate = 0;
	}
	while(--i >= 0)
	{
		pthread_mutex_init(&fork[i], NULL);
	}
	return (philo);
}

 void	start_philo(t_philo *philo)
 {
 }