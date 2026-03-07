/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:14:01 by dana              #+#    #+#             */
/*   Updated: 2025/02/08 13:39:29 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void send_bit(int pid, char bit)
{
    if (bit == '1')
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(100);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		j;
	if (argc < 3)
		return (-1);
	pid = atoi(argv[1]);
	i = -1;
	while(argv[2][++i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if((argv[2][i] >> j) & 1)
				send_bit(pid, '1');
			else
				send_bit(pid, '0');
			j--;
		}
	}
	j = 8;
	while (--j >= 0)
		send_bit(pid, '0');
	return (0);
}
