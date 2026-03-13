/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:41:55 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/12 10:42:39 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit_counter;
	static int	client_pid;

	(void)context;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (bit_counter <= 7)
	{
		c = c << 1;
		bit_counter++;
		if (sig == SIGUSR1)
			c = c | 1;
	}
	if (bit_counter > 7)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		c = 0;
		bit_counter = 0;
	}
	kill(client_pid, SIGUSR1);
}

void	sig_error(void)
{
	write(2, "SIGACTION error\n", 16);
	exit(1);
}

int	main(void)
{
	int 			pid;
	struct sigaction sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		sig_error();
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		sig_error();
	while (1)
	{
		pause();
	}
	return (0);
}
