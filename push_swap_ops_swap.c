/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:18:28 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/13 19:00:45 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node** stack)
{
	if (*stack && (*stack)->next)
	{
		t_node* first = *stack;
		t_node* second = (*stack)->next;
		first->next = second->next;
		second->prev = first->prev;
		if (first->next) first->next->prev = first;
		second->next = first;
		*stack = second;
	}
}

void	sa(t_node **node_a, t_node **node_b)
{
	swap(node_a);
	printf("%s", "########## op: sa ##########\n\n");
	print_stacks(*node_a, *node_b);
}


void	sb(t_node **node_a, t_node **node_b)
{
	swap(node_b);
	printf("%s", "########## op: sb ##########\n\n");
	print_stacks(*node_a, *node_b);
}

void	ss(t_node **node_a, t_node **node_b)
{
	swap(node_a);
	swap(node_b);
	printf("%s", "########## op: ss ##########\n\n");
	print_stacks(*node_a, *node_b);
}