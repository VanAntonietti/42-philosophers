/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:59:23 by vantonie          #+#    #+#             */
/*   Updated: 2023/01/03 16:00:51 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validation(t_data *data)
{
	if (data->n_philo < 1)
		printf("Wrong number of philosophers, must be greater than 1\n");
	else if (data->time_to_die < 40 || data->time_to_eat < 40
		|| data->time_to_sleep < 40)
		printf("Time must me greater than 40\n");
	else if (data->s_argc == 6 && data->times_must_eat < 1)
		printf("Times must eat must be greater or equalto 1\n");
	else if (data->s_argc == 5 || data->s_argc == 6)
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	dest;

	i = 0;
	if (*str == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	dest = 0;
	while ((48 <= str[i]) && (str[i] <= 57))
	{
		dest = dest * 10;
		dest = dest + (str[i] - 48);
		i++;
	}
	return (dest * minus);
}

long long	current_time(void)
{
	struct timeval	time;
	long long		current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

int	end_dinner(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	else if (philo->times_ate == philo->data->times_must_eat)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

void	mssleep(int time)
{
	usleep(time * 1000);
}
