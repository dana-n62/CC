/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:45:12 by DaNa              #+#    #+#             */
/*   Updated: 2025/11/23 12:13:25 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//changes a string into an integer without handeling overflow
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	number;
	int			sign;
	int			i;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return ((int)number * sign);
}
