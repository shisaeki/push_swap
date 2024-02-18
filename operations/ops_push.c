/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:46:11 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 15:25:56 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **source, t_node **target)
{
	if (*source)
	{
		t_node *top = *source;
		*source = top->next;
		if (*source) (*source)->prev = NULL;
		top->next = *target;
		if (*target) (*target)->prev = top;
		*target = top;
	}
}

void	pa(t_node **node_a, t_node **node_b)
{
	push(node_b, node_a);
	printf("%s", "########## op: pa ##########\n");
	print_stacks(*node_a, *node_b);
}

void	pb(t_node **node_a, t_node **node_b)
{
	push(node_a, node_b);
	printf("%s", "########## op: pb ##########\n");
	print_stacks(*node_a, *node_b);
}