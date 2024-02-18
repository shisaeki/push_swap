/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three_or_less.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:30:53 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 15:30:53 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_a_two(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, stack_b);
}

void	sort_stack_b_two(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_b)->data > (*stack_b)->next->data)
		sb(stack_a, stack_b);
}

void	sort_stack_a_three(t_node **stack_a, t_node **stack_b)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->data;
	middle = (*stack_a)->next->data;
	bottom = (*stack_a)->next->next->data;
	if (top < middle && middle < bottom)
		return;
	if (top < middle && middle > bottom && top < bottom)
	{
		rra(stack_a, stack_b);
		sa(stack_a, stack_b);
	}
	else if (top > middle && middle < bottom && top < bottom)
		sa(stack_a, stack_b);
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a, stack_b);
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack_a, stack_b);
	else if (top > middle && middle > bottom)
	{
		ra(stack_a, stack_b);
		sa(stack_a, stack_b);
	}
}

void	sort_stack_b_three(t_node **stack_a, t_node **stack_b)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_b)->data;
	middle = (*stack_b)->next->data;
	bottom = (*stack_b)->next->next->data;
	if (top < middle && middle < bottom)
		return;
	if (top < middle && middle > bottom && top < bottom)
	{
		rrb(stack_a, stack_b);
		sb(stack_a, stack_b);
	}
	else if (top > middle && middle < bottom && top < bottom)
		sb(stack_a, stack_b);
	else if (top < middle && middle > bottom && top > bottom)
		rrb(stack_a, stack_b);
	else if (top > middle && middle < bottom && top > bottom)
		rb(stack_a, stack_b);
	else if (top > middle && middle > bottom)
	{
		rb(stack_a, stack_b);
		sb(stack_a, stack_b);
	}
}

void	push_swap_three_or_less(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_stack_a_two(stack_a, stack_b);
	else if (size == 3)
		sort_stack_a_three(stack_a, stack_b);
	else
		return ;
}