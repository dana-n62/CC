/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:54:47 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/01/08 16:24:10 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//this part is responsible for building the linked lists
//what it does: 1- create node, 2- links node, 3- free stack
void	free_stack(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !*stack) //make sure to look into !stack
		return ;
	while (*stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
	*stack = NULL;
	stack = NULL;
}

t_stack	*new_node(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->value = data;
	new->cost_a = 0;
	new->cost_b = 0;
	new->index = 0;
	new->position = 0;
	new->target_position = 0;
	new->next = NULL;
	return (new);
}
void	add_bottom(t_stack **stack, int data)
{
	t_stack	*last;
	t_stack	*new;

	new = new_node(data);
	if (!stack || !*stack)
		*stack = new;
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
