/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:39:47 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/09 15:17:30 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack_a)
{
	int		index;
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
	int		pos;

	current = *stack;
	pos = 0;
	while (current)
	{
		current->position = pos;
		pos++;
		current = current->next;
	}
}

int	choose_larger(int a, int b)
{
	int	new_a;
	int	new_b;

	new_a = ft_abs(a);
	new_b = ft_abs(b);
	if (new_a > new_b)
		return (new_a);
	return (new_b);
}
