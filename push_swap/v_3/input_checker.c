/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:21:39 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 16:23:12 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//this part is meant to check the validty of the input:
//1-all integers, 2- no duplicates
//it also coverts from string to long int
//if content is validated then a list is returned to main function

void	error_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}
int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
long	ft_atol(const char *str)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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
	return (number * sign);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*loop;

	current = stack;
	while (current)
	{
		loop = current->next;
		while (loop)
		{
			if (current->value == loop->value)
				return (1);
			loop = loop->next;
		}
		current = current->next;
	}
	return (0);
}
