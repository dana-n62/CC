/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 04:43:32 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 16:32:26 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//this part is responsible for converting the input into a stack
//checks whether the input is one string or multiple and acts upon it
//the over flow from atol is checked here
void	free_split(char **string)
{
	int	i;

	i = 0;
	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	free(string);
}

static t_stack	*create_stack(char **string)
{
	t_stack	*stack;
	int	i;
	long	num;

	stack = NULL;
	i = -1;
	while (string[++i] != NULL)
	{
		num = ft_atol(string[i]);
		if (is_valid_number(string[i]) && (num <= INT_MAX && num >= INT_MIN))
			add_bottom(&stack, (int)num);
		else
		{
			free_stack(&stack);
			return (NULL);
		}
	}
	if (!stack || has_duplicates(stack))
	{
		free_stack(&stack);
		return (NULL);
	}
	return (stack);
}
t_stack	*build_stack(char **argv, int argc)
{
	t_stack	*new_stack;
	char	**int_list;

	new_stack = NULL;
	if (argc == 2)
	{
		int_list = ft_split(argv[1], ' ');
		if (!int_list)
			error_exit();
		new_stack = create_stack(int_list);
		free_split(int_list);
	}
	else if(argc > 2)
		new_stack = create_stack(&argv[1]);
	if (!new_stack || new_stack == NULL)
		error_exit();
	return (new_stack);
}
