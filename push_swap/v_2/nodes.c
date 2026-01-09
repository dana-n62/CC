/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:54:47 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/24 12:36:54 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_nodes(t_list **stack)
{
	ft_lstclear(stack, free);
}
void	create_add_nodes(t_list **pointer, int data)
{
	t_list	*new_node;

	new_node = ft_lstnew(data);
	if (!new_node)
		return ;
	ft_lstadd_front(pointer, new_node);
}
