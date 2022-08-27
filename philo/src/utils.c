/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:28:33 by vantonie          #+#    #+#             */
/*   Updated: 2022/06/24 11:26:02 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validation(int argc, char **argv)
{
	if(atoi(argv[2]) > MAX_INT)
		return(1);
	if(argc >=7)
		return(1);
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
