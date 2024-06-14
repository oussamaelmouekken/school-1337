/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:21:34 by oel-moue          #+#    #+#             */
/*   Updated: 2024/04/05 14:37:43 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	byts_to_caracters(int sig)
{
	static char	str;
	static int	bit;

	if (sig == SIGUSR1)
	{
		str = (str << 1) | 1;
		bit++;
	}
	else if (sig == SIGUSR2)
	{
		str = (str << 1);
		bit++;
	}
	if (bit == 8)
	{
		write(1, &str, 1);
		str = 0;
		bit = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, byts_to_caracters);
	signal(SIGUSR2, byts_to_caracters);
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
	}
	return (0);
}
