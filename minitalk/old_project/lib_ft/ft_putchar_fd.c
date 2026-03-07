/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:24:57 by dana              #+#    #+#             */
/*   Updated: 2024/09/15 03:23:28 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>
//print charachter to file given  
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
/*int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	fd;
		ssize_t	holder;
		char	buffer[100];

		fd = open("test.txt", O_RDWR);
		if (fd > 0)
		{
			ft_putchar_fd(argv[1][0], fd);
			holder = read(fd, buffer, sizeof(buffer) - 1);
			while (holder > 0)
			{
				printf("%s\n", buffer);
				buffer[holder] = '\0';
				holder = read(fd, buffer, sizeof(buffer) - 1);
			}	
		}
		else
		{
			printf("error\n");
			return -1;
		}
	}
	return (0);
}*/
