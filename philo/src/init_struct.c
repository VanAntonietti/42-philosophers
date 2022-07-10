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

void	init_struct(t_philo *philo, int argc, char **argv)
{
	philo->s_argc = argc;
	philo->s_argv = argv;
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (philo->s_argc == 6)
		philo->time_must_eat = ft_atoi(argv[5]);
	philo->time = 0;
}