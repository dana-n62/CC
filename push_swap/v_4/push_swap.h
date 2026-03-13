/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:18 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/11 10:30:13 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

int		find_min_pos(t_stack *stack);
int		find_max_pos(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);

void	free_stack(t_stack **stack);
t_stack	*new_node(int data);
void	add_bottom(t_stack **stack, int data);

void	rr(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);

void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

long	ft_atol(const char *str);
int		is_valid_number(char *str);
void	error_exit(void);
int		has_duplicates(t_stack *stack);

t_stack	*build_stack(char **argv, int argc);
void	free_split(char **string);

void	assign_positions(t_stack **stack);
void	assign_index(t_stack *stack_a);
int		choose_larger(int a, int b);

void	sort_three(t_stack **stack_a);
void	sort_two(t_stack **stack_a);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size);

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b, int size);
int		stack_size(t_stack *stack);

void	find_target_position_a(t_stack **stack_a, t_stack **stack_b);
void	find_target_position_b(t_stack **stack_a, t_stack **stack_b);
void	calculate_costs_a(t_stack **stack_a, t_stack **stack_b);
void	calculate_costs_b(t_stack **stack_a, t_stack **stack_b);
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b, char a_b);

int		ft_abs(int x);
int		is_sorted(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	rotate_a(t_stack **stack_a, int *cost_a);
void	rotate_b(t_stack **stack_b, int *cost_b);
#endif
