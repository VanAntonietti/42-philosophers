/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:18:49 by vantonie          #+#    #+#             */
/*   Updated: 2022/06/24 11:21:37 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void time_in_miliseconds(t_philo *philo)
{
	gettimeofday(&philo->start, NULL);
	philo->time = (double) (philo->start.tv_sec * 1000) + (philo->start.tv_usec / 1000);
	printf("%f\n", philo->time);
}

int	philosophers(t_philo *philo)
{
	time_in_miliseconds(philo);
	return (0);
}