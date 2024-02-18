/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:57 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 16:04:20 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rotate(t_node** stack)
{
	if (*stack && (*stack)->next)
	{
		t_node* first = *stack;
		while (first->next)
		{
			first = first->next;
		}
		first->next = *stack;
		(*stack)->prev = first;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}

void	ra(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	printf("%s", "########## op: ra ##########\n\n");
	print_stacks(*stack_a, *stack_b);
}

void	rb(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_b);
	printf("%s", "########## op: rb ##########\n\n");
	print_stacks(*stack_a, *stack_b);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("%s", "########## op: rr ##########\n\n");
	print_stacks(*stack_a, *stack_b);
}