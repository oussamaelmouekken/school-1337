/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 02:00:14 by oel-moue          #+#    #+#             */
/*   Updated: 2024/04/17 19:49:17 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	byts_to_caracters(int sig, siginfo_t *info, void *d)
{
	static char	str;
	static int	bit;

	(void)d;
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
		if (str == '\0')
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &str, 1);
		str = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = &byts_to_caracters;
	if (sigaction(SIGUSR1, &s, 0) == -1 || sigaction(SIGUSR2, &s, 0) == -1)
	{
		ft_printf("Error sigaction\n");
		exit(1);
	}
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
	}
	return (0);
}
