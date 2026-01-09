/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:57:54 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 17:29:43 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//main sorting engine: 1- sort stack, 2- sort_two, 3- sort_three
void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	max;

	max = find_max(*stack_a);
	if ((*stack_a)->value == max)
		ra(stack_a);
	else if ((*stack_a)->next->value == max)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		turk_algorithm(stack_a, stack_b, size);
}
