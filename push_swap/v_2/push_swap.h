/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:18 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/12/08 12:10:47 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	push_swap(int argc, char *argv);
int     *input_checker(char *argv);
void	create_add_nodes(t_list **pointer, int data);
void	free_all_nodes(t_list **stack);
int		is_sorted(int array, int size);
void	swap(int *stack, int size);
void	swap_ss(int *stack_a, int *stack_b, int size_a, int size_b);
int		is_empty(int top);
int		is_full(int top, int size);
void	push_a(int *stack_a, int *stack_b, int top_a, int top_b, int size_a);
void	push_b(int *stack_a, int *stack_b, int top_a, int top_b, int size_b);
int		pop(int *stack, int top);
void	rotate(int *stack, int top);
void	rotate_both(int *stack_a, int *stack_b, int top_a, int top_b);
void	rr_both(int *stack_a, int *stack_b, int top_a, int top_b);
void	reverse_rotate(int *stack, int top);
#endif
