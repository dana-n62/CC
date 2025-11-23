/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:14:38 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/19 12:24:11 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//keeps track of sorted stacks
int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (-1);
		stack = stack->next;
	}
	return (1);
}
//the main engine of the project, creates lists pointers
//calls function to cjeck and create nodes, calls function to sort data
//clears all data and frees all memory blocks
void	push_swap(char *argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	sort_checker;

	if (!argv || argv[0] == '\0')
		exit(1);
	input_checker(argv, &stack_a);
	sort_checker = is_sorted(stack_a);
	if (sort_checker < 0)
	{//apply algorith, pass stack_a and stack_b
	}
	ft_lstiter(stack_a, ft_printf);
	//add function to check all data is free and if not free it
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	return ;
}
