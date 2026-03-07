/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:42:16 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/07 09:40:28 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	error_handler()
{
	write(2, "Error\nWrong PID\n", 16);
	exit(1);
}
int	str_len(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}
void	send_signal(char c, int pid)
{
	int	j;

	j = 8;
	while (--j >= 0)
	{
		if ((c >> j & 1) == 1)
			{
				if(kill(pid, SIGUSR1) < 0)
				error_handler();
			}
		else
			if (kill(pid, SIGUSR2) < 0)
				error_handler();
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	pid;
	int	size;

	if (argc == 3 && argv[2][0] != '\0')
	{
		if ((pid = atoi(argv[1])) <= 0)
			error_handler();
		size = str_len(argv[2]);
		i = -1;
		while (++i <= size)
		{
			send_signal(argv[2][i], pid);
		}
	}
	else
		printf("Error, please enter a valid PID followed by one string\n");
	return (0);
}
