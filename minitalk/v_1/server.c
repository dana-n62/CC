/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:41:55 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/07 09:34:53 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
// put to wait until a signal is received
//it should only exit when a termination signal is sent
//if any signal else is received its supposed to store it in a buffer
//and print it one character at a time
void	handler(int sig)
{
	static char c;
	static int bit_counter;

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
}
void	sig_error()
{
	write(2, "SIGACTION error\n", 16);
	exit(1);
}

int	main(void)
{
	int pid;
	struct sigaction sa;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	sa.sa_handler = &handler;
	sa.sa_flags = 0;
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
