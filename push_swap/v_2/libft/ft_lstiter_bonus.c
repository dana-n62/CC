/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:30:40 by DaNa              #+#    #+#             */
/*   Updated: 2025/11/17 20:34:03 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Iterates through the list ’lst’ and applies the
//function ’f’ to the content of each node.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
