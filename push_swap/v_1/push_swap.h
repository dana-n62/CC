/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:18 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/11/10 13:02:30 by Dana Nour        ###   ########.fr       */
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
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
#endif
