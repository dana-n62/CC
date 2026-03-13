/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:41:55 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/08 15:46:07 by dna2             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_string;

void	add_char(char c)
{
	char		*new_string;
	static int	length;
	int			i;

	if (c != '\0')
	{
		i = -1;
		new_string = malloc(length + 2);
		if (!new_string)
			sig_error();
		while (++i < length)
			new_string[i] = g_string[i];
		new_string[length] = c;
		new_string[length + 1] = '\0';
		length++;
		if (g_string)
			free(g_string);
		g_string = new_string;
		return ;
	}
	ft_printf("%s\n", g_string);
	free(g_string);
	g_string = NULL;
	length = 0;
}

void	sig_error(void)
{
	write(2, "SIGACTION error\n", 16);
	exit(1);
}

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
		add_char(c);
		c = 0;
		bit_counter = 0;
	}
	if (kill(client_pid, SIGUSR1) < 0)
		sig_error();
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_bzero(&sa, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
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
