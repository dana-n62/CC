/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:08:53 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/11 10:30:23 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_stack	*current;
	int		size;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

static void	assign_stacks_positions(t_stack **from_stack, t_stack **to_stack)
{
	assign_positions(from_stack);
	assign_positions(to_stack);
}

static void	re_locate_min(t_stack **stack_a, int size)
{
	int	i;

	i = find_min_pos(*stack_a);
	if (i > 0)
	{
		if (i <= size / 2)
		{
			while (i > 0)
			{
				ra(stack_a);
				i = find_min_pos(*stack_a);
			}
		}
		else
		{
			while (i > 0)
			{
				rra(stack_a);
				i = find_min_pos(*stack_a);
			}
		}
	}
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pb(stack_a, stack_b);
		i++;
	}
	sort_two(stack_b);
	while (stack_size((*stack_a)) > 3)
	{
		assign_stacks_positions(stack_a, stack_b);
		find_target_position_b(stack_a, stack_b);
		calculate_costs_b(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b, 'b');
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_stacks_positions(stack_a, stack_b);
		find_target_position_a(stack_a, stack_b);
		calculate_costs_a(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b, 'a');
	}
	re_locate_min(stack_a, size);
}
