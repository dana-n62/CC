/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:05 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/03 13:47:41 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, int top)
{
	int	i;
	int	temp;

	if (is_empty(top))
		exit(1);
	i = 0;
	temp = stack[0];
	while (i < top)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}
void	rotate_both(int *stack_a, int *stack_b, int top_a, int top_b)
{
	rotate(stack_a, top_a);
	rotate(stack_b, top_b);
}
