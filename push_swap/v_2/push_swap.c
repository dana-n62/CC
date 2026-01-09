/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:14:38 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/12/14 09:11:53 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//checks for already sorted data
int	is_sorted(int *array, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		if (array[i] > array[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
//the main engine of the project, creates lists pointers
//calls function to check and create nodes, calls function to sort data
//clears all data and frees all memory blocks
void	push_swap(int argc, char *argv)
{
	int	*input;
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;

	if (!argv || argv[1] == '\0' || argc < 2)
		return ;
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		input = input_checker(argv[i]);
		//create node for stack_a and put data there
		i++;
	}
/* 	if (is_sorted(input, i) < 0)
	{
		while (i++ > 0)
			create_add_nodes(&stack_a, input[i]);
			//sorting algorithm
	} */
	ft_lstiter(&stack_a, ft_printf);
	free_all_nodes(&stack_a);
	free_all_nodes(&stack_b);
	return ;
}
