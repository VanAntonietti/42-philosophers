/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:18:49 by vantonie          #+#    #+#             */
/*   Updated: 2022/06/24 11:27:08 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*time_in_miliseconds(t_philo *philo)
{
	gettimeofday(&philo->start, NULL);
	philo->time = (double)(philo->start.tv_sec * 1000)
		+ (philo->start.tv_usec / 1000);
	printf("%f\n", philo->time);
	pthread_join(*philo->philo1, NULL);
	pthread_join(*philo->philo2, NULL);
	pthread_join(*philo->philo3, NULL);
	return (NULL);
}

int	philosophers(t_philo *philo)
{
	pthread_create(philo->philo1, NULL, time_in_miliseconds(philo), NULL);
	pthread_create(philo->philo2, NULL, time_in_miliseconds(philo), NULL);
	pthread_create(philo->philo3, NULL, time_in_miliseconds(philo), NULL);
	return (0);
}
