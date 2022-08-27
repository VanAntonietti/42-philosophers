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

void	*routine(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	printf("%d\n", philo->data->n_philo);
	return(tmp);
}

void	philosophers(t_philo **philo)
{
	int	i;

	i = 0;
	while(i < philo[i]->data->n_philo)
	{
		pthread_create(philo[i]->thread, NULL, &routine, &philo[i]);
		i++;
	}
}