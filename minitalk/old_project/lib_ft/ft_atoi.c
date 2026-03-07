/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:06:58 by dana              #+#    #+#             */
/*   Updated: 2024/09/22 12:44:39 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	minus;

	i = 0;
	nbr = 0;
	minus = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (ft_isdigit(str[i]))
		nbr = nbr * 10 + (str[i++] - '0');
	if (minus)
		return (nbr * -1);
	return (nbr);
}
/*int   main(int argc, char **argv)
{
	if (argc > 1)
	{
        	int number = ft_atoi(argv[1]);
        	printf("%d\n", number);
		printf("%d\n", atoi(argv[1]));
	}
        return (0);
}*/
