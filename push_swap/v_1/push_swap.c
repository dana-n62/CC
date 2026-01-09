/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:21:12 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/10 13:03:23 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* void	create_nodes(char *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
} */

void	push_swap(char *argv)
{
	node	*data;
	int	size;
	//int	i;

	if (!argv || argv[0] == '\0')
		return ;
	//i = 0;
	size = checker(*argv);
	if (size < 0)
	{
		printf("ERROR!\n");
		exit(1);
	}
	//create_nodes(data, size);
	//free(data);
	return ;
}
