/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:49 by vantonie          #+#    #+#             */
/*   Updated: 2023/01/02 16:35:28 by vantonie         ###   ########.fr       */
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

typedef pthread_mutex_t t_mutex;

typedef struct s_data
{
	int			n_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_must_eat;
	long long	start_time;
	int			s_argc;
	char		**s_argv;
	int			dead;
	t_mutex		lock;
	t_mutex		lock_print;
}				t_data;

typedef struct s_philo
{
	t_data		*data;
	pthread_t	thread;
	t_mutex		*fork;
	int			id;
	long long	last_meal;
	int			times_ate;
}				t_philo;

int			ft_atoi(const char *str);
int			validation(t_data *data);
void		init(t_data *data, int argc, char **argv);
void		init_data(t_data *data, int argc, char **argv);
t_philo		*init_philo(t_data *data);
void		start_philo(t_philo *philo);
long long	current_time(void);
int			end_dinner(t_philo *philo);
void		mssleep(int time);
void		print_action(t_philo *philo, char *action);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
int			try_eat(t_philo *philo);
void		*routine(void *arg);
void		*monitor_routine(void *arg);


#endif