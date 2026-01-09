/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:45:22 by DaNa              #+#    #+#             */
/*   Updated: 2025/11/17 20:35:55 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Adds the node ’new’ at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
