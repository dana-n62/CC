/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 04:02:04 by dana              #+#    #+#             */
/*   Updated: 2024/09/26 13:09:05 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>
void	ft_putnbr_fd(int n, int fd)
{
	int		value;
	char	temp;

	value = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		value = n * (-1);
	}
	else
	{
		value = n;
	}
	if (value / 10 != 0)
	{
		ft_putnbr_fd(value / 10, fd);
	}
	temp = value % 10 + 48;
	write(fd, &temp, sizeof(temp));
}
/*void	ft_putnbr_fd(int n, int fd)
{
	char	*num;
	int		i;

	num = ft_itoa(n);
	i = 0;
	while (num[i] != '\0')
	{
		write(fd, &num[i], sizeof(num[i]));
		i++;
	}
	free(num);
}
int	main(void)
{
	int fdi = open ("test.txt", O_RDWR | O_CREAT, 0644);
	if (fdi > 0)
		ft_putnbr_fd(-48, fdi);
	return (0);
}*/
