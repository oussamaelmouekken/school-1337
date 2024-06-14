/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:21:55 by oel-moue          #+#    #+#             */
/*   Updated: 2024/04/18 11:47:19 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		(ft_printf("error pid"), exit(1));
	return (sign * nb);
}

void	caracter_to_bits(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("error \n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("error\n");
				exit(1);
			}
		}
		usleep(500);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		if (pid <= 0)
		{
			ft_printf("error PID \n");
			exit(1);
		}
		i = 0;
		while (str[i])
		{
			caracter_to_bits(pid, str[i]);
			i++;
		}
	}
	else
		ft_printf("error argument\n");
	exit(1);
}
