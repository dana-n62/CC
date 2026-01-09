/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:35 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 16:21:22 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//swap is static to make it a local function, its a good practice for helper functions not needed elsewhere to avoid name conflicts
//the functions should always type when they are called, even if 1 element was in the stack
static void	swap(t_stack **stack)
{
	int	temp_value;
	int	temp_index;

	if (!*stack || !(*stack)->next)
		return ;
	temp_value = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp_value;
	temp_index = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp_index;
}
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
