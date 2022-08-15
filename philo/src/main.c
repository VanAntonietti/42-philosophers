/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:09:54 by vantonie          #+#    #+#             */
/*   Updated: 2022/08/15 07:46:22 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (argc == 5 || argc == 6)
	{
		init_struct(philo, argc, argv);
		init_thread(philo);
	}
	return (0);
}
