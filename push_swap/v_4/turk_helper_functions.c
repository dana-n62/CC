/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:39:08 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/09 14:50:39 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//
int	is_sorted(t_stack *stack)
{
	t_stack	*next;

	while (stack && stack->next != NULL)
	{
		next = stack->next;
		if (stack->value < next->value)
			stack = next;
		else
			return (0);
	}
	return (1);
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a != 0)
	{
		if (*cost_a > 0)
		{
			ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(stack_a);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b != 0)
	{
		if (*cost_b > 0)
		{
			rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(stack_b);
			(*cost_b)++;
		}
	}
}

int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
