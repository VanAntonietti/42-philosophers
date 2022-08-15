/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:18:49 by vantonie          #+#    #+#             */
/*   Updated: 2022/08/15 07:56:25 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_philo *philo)
{
	
	return (0);
}

void	init_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->n_philosophers)
	{
		pthread_create(&philo->threads[i], NULL, philosophers, NULL);
		i++;
	}
	while(i > 0)
	{
		pthread_join(philo->threads[i], NULL);
		i--;
	}
}

