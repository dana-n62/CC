/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:45 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 16:20:20 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **source_stack, t_stack **dest_stack)
{
	t_stack	*temp;

	if (!source_stack || !*source_stack)
		return ;
	temp = *source_stack;
	*source_stack = (*source_stack)->next;
	temp->next = *dest_stack;
	*dest_stack = temp;
}
//from b->a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}
//from a->b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
