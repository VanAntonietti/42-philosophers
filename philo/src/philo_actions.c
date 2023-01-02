#include "philo.h"

int	try_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[0]);
	pthread_mutex_lock(&philo->fork[1]);
	if(end_dinner(philo) == 1)
	{
		pthread_mutex_unlock(&philo->fork[0]);
		pthread_mutex_unlock(&philo->fork[1]);
		return (0);
	}
	print_action(philo, "has taken a fork");
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->lock);
	philo->times_ate++;
	philo->last_meal = current_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->lock);
	mssleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork[0]);
	pthread_mutex_unlock(&philo->fork[1]);
	return (1);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	mssleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
	usleep(1000);
}

void	print_action(t_philo *philo, char *action)
{
	long long int	time;

	time = current_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%lld %d %s\n", time, philo->id + 1, action);
	pthread_mutex_unlock(&philo->data->lock_print);
}