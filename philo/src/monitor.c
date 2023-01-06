/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:53:24 by vantonie          #+#    #+#             */
/*   Updated: 2023/01/06 21:09:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	verify_death(t_philo *monitor, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_lock(&monitor[i].data->lock);
		if ((current_time() - data->start_time) - monitor[i].last_meal
			> data->time_to_die
			&& monitor[i].times_ate != data->times_must_eat)
		{
			print_action(&monitor[i], "died");
			data->dead = 1;
			pthread_mutex_unlock(&monitor[i].data->lock);
			return (-1);
		}
		pthread_mutex_unlock(&monitor[i].data->lock);
	}
	return (0);
}

static int	verify_monitor(t_philo *monitor, t_data *data)
{
	int	i;
	int	not_satisfied;

	not_satisfied = data->n_philo;
	while (not_satisfied != 0 && data->dead == 0)
	{
		usleep(300);
		i = verify_death(monitor, data);
		if (i == -1)
			return (-1);
		not_satisfied = data->n_philo;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&monitor[i].data->lock);
			if (monitor[i].times_ate == data->times_must_eat)
				not_satisfied--;
			pthread_mutex_unlock(&monitor[i].data->lock);
			i++;
		}
	}
	return (not_satisfied);
}

void	*monitor_routine(void *arg)
{
	int		i;
	t_philo	*monitor;

	monitor = (t_philo *)arg;
	i = verify_monitor(monitor, monitor[0].data);
	if (i == 0)
	{
		print_action(&monitor[0], "everyone ate");
	}
	return (NULL);
}
