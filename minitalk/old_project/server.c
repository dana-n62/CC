/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:01:16 by dana              #+#    #+#             */
/*   Updated: 2025/02/13 13:44:03 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
char	bit_received = '\0';

void	print_to_screen(char *string)
{
	int	i;

	i = 0;
	while (i < (int)strlen(string))
	{
		write(1, &string[i], 1);
		i++;
	}
}
void	bit_handler(int	signum)
{
	static int	bit_counter;
	static char	*string;
	static int		size = 1;

	bit_received <<= 1;
	if (signum == SIGUSR1)
		bit_received |= 1;
	else if (signum == SIGUSR2)
		bit_received |= 0;
	bit_counter++;
	if (bit_counter == 8)
	{
		if (bit_received == '\0')
			write(1, "\n", 1);
		else
		{
			string = malloc(size + 1);
			string[size - 1] = bit_received;
			size++;
		}
		bit_counter = 0;
		bit_received = '\0';
	}
	string[size] = '\0';
	print_to_screen(string);
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_handler = bit_handler;
	sa.sa_flags =  0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error with signal\n", 18);
		return (1);
	}
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
