/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:12:40 by dana              #+#    #+#             */
/*   Updated: 2024/09/26 08:42:35 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//transform int to char, seperate size of int function
static	int	size(int val)
{
	int	s;

	s = 0;
	if (val == 0)
		return (1);
	if (val < 0)
	{
		s++;
		val *= -1;
	}
	while (val > 0)
	{
		s++;
		val /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*number;
	size_t		i;

	i = (size_t)size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = (char *)malloc((i * sizeof(char)) + 1);
	if (number == NULL)
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	if (n == 0)
		number [0] = '0';
	number[i] = '\0';
	while (n > 0)
	{
		number[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (number);
}
/*int	main(void)
{
	char	*test = ft_itoa(0);
	printf("%s\n", test);
	return (0);
}*/
