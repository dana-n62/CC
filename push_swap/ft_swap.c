/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:35 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/03 13:43:36 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	swap(int *stack, int size)
{
	int	temp;

	if (size <= 1)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}
void	swap_ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	swap(stack_a, size_a);
	swap(stack_b, size_b);
}
