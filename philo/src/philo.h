/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:02:56 by vantonie          #+#    #+#             */
/*   Updated: 2022/08/15 07:53:09 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_table
{
	int *fork;
}			t_table;

typedef struct s_philo
{
	int				s_argc;
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	char			**s_argv;
	double			time;
	pthread_t		*threads;
	struct timeval	start;
	struct timeval	stop;
}			t_philo;

int		ft_atoi(const char *str);
int		philosophers(t_philo *philo);
void	init_struct(t_philo *philo, int argc, char **argv);
void	thread_create(t_philo *philo);
void	init_thread(t_philo *philo);

#endif