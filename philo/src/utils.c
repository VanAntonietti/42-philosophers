#include "philo.h"

int	validation(int argc, char **argv)
{
	return(0);
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
