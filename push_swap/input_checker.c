/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:21:39 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/19 12:53:24 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//this functio is meant to check the validty of the input (all integers)
//if content is validated then a node is created for it
void	input_checker(char *argv, t_list **pointer_stack_a)
{
	int	i;
	int	data;
	t_list *new_node;

	i = 0;
	while (argv[i] != '\0')
	{
		if(ft_isdigit(argv[i]))
		{
			data = ft_atoi(argv[i]);
			
		}
		i++;
	}
}
