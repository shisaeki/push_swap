/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:31:56 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 01:21:04 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node **stack)
{
	int		count;
	t_node	*tmp;

	if (*stack == NULL)
		return (0);
	count = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	init_stack(t_node **node, int *arr, int *sorted, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		insert_at_end(node, arr[i], find_rank(sorted, len, arr[i]));
		i++;
	}
}

void	print_stack(t_node *node)
{
	while (node != NULL)
	{
		printf("%d(rank: %d) ", node->data, node->rank);
		node = node->next;
	}
	printf("\n");
}

void	print_stacks(t_node *node_a, t_node *node_b)
{
	printf("%-20s %-20s\n", "STACK_A", "STACK_B");
	printf("%-20s %-20s\n", "--------------------", "--------------------");
	while (node_a != NULL || node_b != NULL)
	{
		if (node_a != NULL)
		{
			printf("%-3d (rank: %-2d)%-7s", node_a->data, node_a->rank, "");
			node_a = node_a->next;
		}
		else
			printf("%-20s", "");
		if (node_b != NULL)
		{
			printf("%-3d (rank: %-2d)%-7s", node_b->data, node_b->rank, "");
			node_b = node_b->next;
		}
		else
			printf("%-20s", "");
		printf("\n");
	}
	printf("\n");
}