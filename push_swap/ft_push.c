/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:45 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/03 13:43:46 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	pop(int *stack, int top)
{
	if (is_empty(top))
		return (top);
	top--;
	return(stack[top + 1]);
}
void	push_a(int *stack_a, int *stack_b, int top_a, int top_b, int size_a)
{
	if (is_empty(top_b) || is_full(top_a, size_a))
		exit(1);
	top_a++;
	stack_a[top_a] = pop(stack_b, top_b);
}

void	push_b(int *stack_a, int *stack_b, int top_a, int top_b, int size_b)
{
	if (is_empty(top_a) || is_full(top_b, size_b))
		exit(1);
	top_b++;
	stack_b[top_b] = pop(stack_a, top_a);
}
