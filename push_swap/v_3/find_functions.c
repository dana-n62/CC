/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:30:26 by DaNa              #+#    #+#             */
/*   Updated: 2026/01/08 17:45:30 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//here are different checks performed accross the program
//1- stack_size, 2- is_sorted, 3- find_max, 4- find_min, 5- find_min_pos, 6- find_max_pos
t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*target;
	int	min_cost;
	int	total_cost;

	target = stack;
	min_cost = INT_MAX;
	while (stack)
	{
		if ((stack->cost_a > 0 && stack->cost_b > 0) || (stack->cost_a < 0 && stack->cost_b < 0))
		{
			if (ft_abs(stack->cost_a) > ft_abs(stack->cost_b))
				total_cost = ft_abs(stack->cost_a);
			else
				total_cost = ft_abs(stack->cost_b);
		}
		else
			total_cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack->next != NULL)
	{
		if (max < stack->next->value)
			max = stack->next->value;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack->next != NULL)
	{
		if (min > stack->next->value)
			min = stack->next->value;
		stack = stack->next;
	}
	return (min);
}

int	find_min_pos(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	if (!stack)
		return (-1);
	min = find_min(stack);
	while (stack)
	{
		if (stack->value == min)
			return (i);
		i++;
		stack = stack->next;
	}
	return (min);
}

int	find_max_pos(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	if (!stack)
		return (-1);
	max = find_max(stack);
	while (stack)
	{
		if (stack->value == max)
			return (i);
		i++;
		stack = stack->next;
	}
	return (max);
}
