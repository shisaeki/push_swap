/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:28:06 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/16 23:22:22 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_node
{
	int				data;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

//doubly_linked_list
t_node	*create_node(int data, int rank);
void	insert_at_end(t_node **head, int data, int rank);
//push_swap_utils
void	init_stack(t_node **node, int *arr, int *sorted, int len);
void	print_stack(t_node *node);
void	print_stacks(t_node *node_a, t_node *node_b);
//sort
void	bubble_sort(int *arr, int count);
int		find_rank(int *sorted, int len, int element);
//swap
void	swap(t_node** stack);
void	sa(t_node **node_a, t_node **node_b);
void	sb(t_node **node_a, t_node **node_b);
void	ss(t_node **head_a, t_node **head_b);
//push
void	push(t_node **source, t_node **target);
void	pa(t_node **node_a, t_node **node_b);
void	pb(t_node **node_a, t_node **node_b);
//rotate
void	rotate(t_node** stack);
void	ra(t_node **node_a, t_node **node_b);
void	rb(t_node **node_a, t_node **node_b);
void	rr(t_node **node_a, t_node **node_b);
//reverse_rotate
void	reverse_rotate(t_node **stack);
void	rra(t_node **node_a, t_node **node_b);
void	rrb(t_node **node_a, t_node **node_b);
void	rrr(t_node **node_a, t_node **node_b);
//push_swap
void	push_swap_three_or_less(t_node **stack_a, t_node **stack_b, int size);
void	push_swap_six_or_less(t_node **stack_a, t_node **stack_b, int size);

#endif