/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_core.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:18:29 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 17:59:26 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//7 functions!! needs serious trimming
//
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

void	find_target_position_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*a;
	int	min_larger_index;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		min_larger_index = INT_MAX;
		while (a)
		{
			if ((b->index < a->index) && (a->index < min_larger_index))
			{
					min_larger_index = a->index;
					b->target_position = a->position;
			}
			a = a->next;
		}
		if (min_larger_index == INT_MAX)
			b->target_position = find_min_pos(*stack_a);
		b = b->next;
	}
}

void	find_target_position_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*a;
	int	max_smaller_index;

	a = *stack_a;
	while (a)
	{
		b = *stack_b;
		max_smaller_index = INT_MIN;
		while (b)
		{
			if ((a->index > b->index) && (b->index > max_smaller_index))
			{
					max_smaller_index = b->index;
					a->target_position = b->position;
			}
			b = b->next;
		}
		if (max_smaller_index == INT_MIN)
			a->target_position = find_max_pos(*stack_b);
		a = a->next;
	}
}
//positive for rotate, negative for reverse rotate, 0 already on top
void	calculate_costs_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int	size_b;
	int	size_a;

	b = *stack_b;
	size_b = stack_size(*stack_b);
	size_a = stack_size(*stack_a);
	while (b)
	{
		if (b->position <= (size_b / 2))
			b->cost_b = b->position;
		else
			b->cost_b = b->position - size_b;
		if (b->target_position <= (size_a / 2))
			b->cost_a = b->target_position;
		else
			b->cost_a = b->target_position - size_a;
		b = b->next;
	}
}

void	calculate_costs_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	int	size_b;
	int	size_a;

	a = *stack_a;
	size_b = stack_size(*stack_b);
	size_a = stack_size(*stack_a);
	while (a)
	{
		if (a->position <= (size_a / 2))
			a->cost_a = a->position;
		else
			a->cost_a = a->position - size_a;
		if (a->target_position <= (size_b / 2))
				a->cost_b = a->target_position;
		else
			a->cost_b = a->target_position - size_b;
		a = a->next;
	}
}

void	execute_cheapest_move_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	int	cost_a;
	int	cost_b;

	target = find_cheapest(*stack_b);
	cost_a = target->cost_a;
	cost_b = target->cost_b;
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);

	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);

	pa(stack_a, stack_b);
}
void	execute_cheapest_move_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	int	cost_a;
	int	cost_b;

	target = find_cheapest(*stack_a);
	cost_a = target->cost_a;
	cost_b = target->cost_b;
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);

	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);

	pb(stack_a, stack_b);
}
