/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:49 by vantonie          #+#    #+#             */
/*   Updated: 2022/12/17 01:05:22 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

typedef struct s_data
{
	int	n_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_must_eat;
}				t_data;

typedef struct s_philo
{
	pthread_t	thread;
	t_data		*data;
}				t_philo;

int		ft_atoi(const char *str);
int		validation(int argc, char **argv);
void	init(t_data *data, int argc, char **argv);
void	init_data(t_data *data, int argc, char **argv);

#endif