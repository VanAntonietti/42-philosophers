/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:02:56 by vantonie          #+#    #+#             */
/*   Updated: 2022/06/24 11:25:23 by vantonie         ###   ########.fr       */
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

typedef struct s_philo
{
	int				s_argc;
	char			**s_argv;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	double			time;
	struct timeval	start;
	struct timeval	stop;
}			t_philo;

void	init_struct(t_philo *philo, int argc, char **argv);
int		philosophers(t_philo *philo);
void	*time_in_miliseconds(t_philo *philo);
int		ft_atoi(const char *str);
#endif