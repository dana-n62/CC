/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:39:47 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 17:40:41 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack_a)
{
	int	index;
	t_stack	*current;
	t_stack	*compare;

	current = stack_a;
	while (current)
	{
		compare = stack_a;
		index = 0;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	assign_positions(t_stack **stack)
{
	t_stack	*current;
	int	pos;

	current = *stack;
	pos = 0;
	while (current)
	{
		current->position = pos;
		pos++;
		current = current->next;
	}
}
