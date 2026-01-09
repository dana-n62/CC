/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:21:12 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/09 15:24:01 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//the main engine of the project
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2 || !argv[1] || argv[1][0] == '\0')
		return (0);
	stack_b = NULL;
	stack_a = build_stack(argv, argc);
	if (!stack_a)
		return (0);
	size = stack_size(stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	assign_index(stack_a);
	sort_stack(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
