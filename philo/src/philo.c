/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:18:49 by vantonie          #+#    #+#             */
/*   Updated: 2022/06/23 20:44:34 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_philo *philo)
{
	gettimeofday(&philo->start, NULL);
	printf("%d\n", philo->number_of_philosophers);
	printf("%d\n", philo->time_to_die);
	printf("%d\n", philo->time_to_eat);
	printf("%d\n", philo->time_to_sleep);
	gettimeofday(&philo->stop, NULL);
	
	philo->time = (double) (philo->stop.tv_sec - philo->start.tv_sec) / 1000;
	printf("%d\n", philo->time);
	return (0);
}