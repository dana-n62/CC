/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:49:11 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/03 13:53:08 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int top)
{
	int	i;
	int	temp;

	if (is_empty(top))
		exit(1);
	i = top;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

void	rr_both(int *stack_a, int *stack_b, int top_a, int top_b)
{
	reverse_rotate(stack_a, top_a);
	reverse_rotate(stack_b, top_b);
}
