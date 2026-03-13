/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:42:16 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/08 15:38:22 by dna2             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal = 0;

void	error_handler(void)
{
	write(2, "Error\nWrong PID\n", 16);
	exit(1);
}

void	hand_shake(int sig)
{
	(void)sig;
	g_signal = 1;
}

void	send_signal(char c, int pid)
{
	int	j;

	j = 8;
	while (--j >= 0)
	{
		if ((c >> j & 1) == 1)
		{
			if (kill(pid, SIGUSR1) < 0)
				error_handler();
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				error_handler();
		}
		while (g_signal == 0)
			usleep(100);
		g_signal = 0;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	int					size;
	struct sigaction	sa;

	if (argc == 3)
	{
		ft_bzero(&sa, sizeof(sa));
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = &hand_shake;
		pid = ft_atoi(argv[1]);
		if (sigaction(SIGUSR1, &sa, NULL) < 0 || pid <= 0)
			error_handler();
		size = ft_strlen(argv[2]);
		i = -1;
		while (++i <= size)
		{
			send_signal(argv[2][i], pid);
		}
	}
	else
		write(2, "Error, please enter a valid PID\n", 31);
	return (0);
}
