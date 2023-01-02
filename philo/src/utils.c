#include "philo.h"

int	validation(t_data *data)
{
	if(data->n_philo < 1)
		printf("Wrong number of philosophers, must be greater than 1\n");
	else if(data->time_to_die < 40 || data->time_to_eat < 40 || data->time_to_sleep < 40)
		printf("Time must me greater than 40\n");
	else if(data->s_argc == 6 && data->times_must_eat >= 1)
		printf("Times must eat must be greater or equal to 1\n");
	else if (data->s_argc == 5 || data->s_argc == 6)
	{
		return (0);
	}
	return(1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	dest;

	i = 0;
	if (*str == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	dest = 0;
	while ((48 <= str[i]) && (str[i] <= 57))
	{
		dest = dest * 10;
		dest = dest + (str[i] - 48);
		i++;
	}
	return (dest * minus);
}
