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

# define MAX_INT 2147483647
#define EAT 1

typedef struct s_data
{
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}			t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		*thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_data			*data; 
}			t_philo;

void	init(t_data *data, t_philo **philo, int argc, char **argv);
void	init_data(t_data *data, int argc, char **argv);
void	init_philo(t_data *data, t_philo **philo);
int		validation(int argc, char **argv);
int		ft_atoi(const char *str);
void	philosophers(t_philo **philo);


#endif