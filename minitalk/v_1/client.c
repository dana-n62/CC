/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:42:16 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/12 10:44:05 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack = 0;

void	error_handler(void)
{
	write(2, "Error\nWrong PID\n", 16);
	exit(1);
}

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
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
		while (g_ack == 0)
			pause();
		g_ack = 0;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	size;
	struct sigaction	sa;

	if (argc == 3)
	{
		ft_bzero(&sa, sizeof(sa));
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = &ack_handler;
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, NULL);
		if ((pid = ft_atoi(argv[1])) <= 0)
			error_handler();
		size = ft_strlen(argv[2]);
		i = -1;
		while (++i <= size)
		{
			send_signal(argv[2][i], pid);
		}
	}
	else
		write(2, "Error, please enter a valid PID followed by one string\n", 56);
	return (0);
}
