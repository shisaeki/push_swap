/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_six_or_less.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:40:33 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/16 23:22:06 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_four(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->rank != 0)
	{
		ra(stack_a, stack_b);
	}
	pb(stack_a, stack_b);
	push_swap_three_or_less(stack_a, stack_b, 3);
	pa(stack_a, stack_b);
}

void	sort_stack_five(t_node **stack_a, t_node **stack_b)
{
	int	count;

	count = 0;
	while (count != 2)
	{
		if ((*stack_a)->rank == count)
		{
			pb(stack_a, stack_b);
			count++;
		}
		ra(stack_a, stack_b);
	}
	push_swap_three_or_less(stack_a, stack_b, 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_stack_six(t_node **stack_a, t_node **stack_b)
{
	int count;

	count = 0;
	while (count != 3)
	{
		if ((*stack_a)->rank == count)
		{
			pb(stack_a, stack_b);
			count++;
		}
		ra(stack_a, stack_b);
	}
	push_swap_three_or_less(stack_a, stack_b, 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	push_swap_six_or_less(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 4)
		sort_stack_four(stack_a, stack_b);
	else if (size == 5)
		sort_stack_five(stack_a, stack_b);
	else if (size == 6)
		sort_stack_six(stack_a, stack_b);
	else
		return ;
}