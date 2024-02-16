/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_reverse_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:13:50 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/13 19:00:07 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_node **stack)
{
	if (*stack && (*stack)->next)
	{
		t_node *last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

void	rra(t_node **node_a, t_node **node_b)
{
	reverse_rotate(node_a);
	printf("%s", "########## op: rra ##########\n\n");
	print_stacks(*node_a, *node_b);
}

void	rrb(t_node **node_a, t_node **node_b)
{
	reverse_rotate(node_b);
	printf("%s", "########## op: rrb ##########\n\n");
	print_stacks(*node_a, *node_b);
}

void	rrr(t_node **node_a, t_node **node_b)
{
	reverse_rotate(node_a);
	reverse_rotate(node_b);
	printf("%s", "########## op: rrr ##########\n\n");
	print_stacks(*node_a, *node_b);
}
