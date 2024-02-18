/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_seven_or_more.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:27:08 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 15:30:45 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_smaller_from_a_to_b(t_node **stack_a, t_node **stack_b, int size)
{
	int	pushed_count;

	pushed_count = 0;
	while (pushed_count < size)
	{
		if ((*stack_a)->rank < size)
		{
			pb(stack_a, stack_b);
			pushed_count++;
		}
		else
			ra(stack_a, stack_b);
	}
}

void	push_higher_from_b_to_a(t_node **stack_a, t_node **stack_b, int size)
{
	int	len;
	int	i;
	int	min_rank;
	int	count;
	t_node	*tmp;

	len = get_stack_size(stack_b);
	i = 0;
	tmp = *stack_b;
	min_rank = -1;
	while (tmp != NULL)
	{
		if (min_rank < 0 || min_rank > tmp->rank)
			min_rank = tmp->rank;
		tmp = tmp->next;
	}
	count = 0;
	while (count < len)
	{
//		printf("stack-rank: %d count:%d min:%d min+size:%d\n", (*stack_b)->rank, count, min_rank, min_rank + size);
		if ((*stack_b)->rank >= min_rank + size)
		{
			pa(stack_a, stack_b);
		}
		else
			rb(stack_a, stack_b);
		count++;
	}
}

void	push_from_a_to_b(t_node **stack_a, t_node **stack_b, int size)
{
	int	pushed_count;

	pushed_count = 0;
	while (pushed_count < size)
	{
		pb(stack_a, stack_b);
		pushed_count++;
	}
}

void	divide_and_sort(t_node **stack_a, t_node **stack_b, int size)
{
	if (get_stack_size(stack_b) == 2)
	{
		sort_stack_b_two(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a, stack_b);
		return ;
	}
	else if (get_stack_size(stack_b) == 3)
	{
		sort_stack_b_three(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a, stack_b);
		return ;
	}
	push_higher_from_b_to_a(stack_a, stack_b, size / 2);
	divide_and_sort(stack_a, stack_b, size / 2);
	push_from_a_to_b(stack_a, stack_b, size - size / 2);
	divide_and_sort(stack_a, stack_b, size - size / 2);
}

void	push_swap(t_node **stack_a, t_node **stack_b, int size)
{
	push_smaller_from_a_to_b(stack_a, stack_b, size / 2);
	divide_and_sort(stack_a, stack_b, size / 2);
	push_from_a_to_b(stack_a, stack_b, size - size / 2);
	divide_and_sort(stack_a, stack_b, size - size / 2);
}
