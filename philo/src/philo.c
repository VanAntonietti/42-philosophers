/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:46 by vantonie          #+#    #+#             */
/*   Updated: 2023/01/07 11:29:27 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_maker(int i, t_philo *philo, t_data *data, t_mutex **fork)
{
	philo[i].data = data;
	philo[i].id = i + 1;
	philo[i].last_meal = 0;
	philo[i].fork = malloc(2 * sizeof(t_mutex *));
	philo[i].fork[0] = fork[i];
	philo[i].fork[1] = fork[(i + 1) % data->n_philo];
	if (i == data->n_philo - 1)
	{
		philo[i].fork[1] = philo[i].fork[0];
		philo[i].fork[0] = fork[0];
	}
	philo[i].times_ate = 0;
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	t_mutex	**fork;
	int		i;

	philo = malloc(data->n_philo * sizeof(t_philo));
	fork = malloc(data->n_philo * sizeof(t_mutex *));
	i = -1;
	while (++i < data->n_philo)
	{
		fork[i] = malloc(sizeof(t_mutex));
		pthread_mutex_init(fork[i], NULL);
	}
	while (--i >= 0)
	{
		philo_maker(i, philo, data, fork);
	}
	data->fork = fork;
	return (philo);
}

void	start_philo(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	philo[0].data->start_time = current_time();
	while (++i < philo[0].data->n_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]);
	}
	pthread_create(&monitor, NULL, &monitor_routine, (void *)philo);
	i = -1;
	while (++i < philo[0].data->n_philo)
	{
		pthread_join(philo[i].thread, NULL);
	}
	pthread_join(monitor, NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philo == 1)
	{
		philo_one(philo);
	}
	if (philo->id % 2 == 0)
		usleep(1400);
	while (end_dinner(philo) == 0 && philo->data->n_philo != 1)
	{
		if (try_eat(philo) == 1 && end_dinner(philo) == 0)
			philo_sleep(philo);
		else
			break ;
		if (end_dinner(philo) == 0)
			philo_think(philo);
	}
	return (NULL);
}
