/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:28:08 by dana              #+#    #+#             */
/*   Updated: 2024/09/15 03:58:52 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>
//write string to file
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	int	fd1;

	fd1 = open ("test.txt", O_RDWR);
	if (argc > 1 && fd1 > 0)
		ft_putstr_fd(argv[1], fd1);
	else
	{
		printf("ERROR\n");
		return (-1);
	}

	return (0);
}*/
