/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:42 by vantonie          #+#    #+#             */
/*   Updated: 2022/12/17 01:04:40 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	init(data, argc, argv);
	printf("%d", data->n_philo);
	printf("%d", data->time_to_die);
	printf("%d", data->time_to_eat);
	printf("%d", data->time_to_sleep);
	printf("%d", data->times_must_eat);
	
	return 0;
}