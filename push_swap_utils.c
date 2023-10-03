/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:57:30 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/03 17:01:46 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_data(int *data)
{
	if (data)
		printf("%d   ", *data);
	else
		printf("    ");
}

void	print_stacks(t_node* initial_node_a, t_node* initial_node_b)
{
	t_node*	tmp_a;
	t_node*	tmp_b;

	tmp_a = initial_node_a->next;
	tmp_b = initial_node_b->next;
	while (tmp_a->data != NULL || tmp_b->data != NULL)
	{
		print_data(tmp_a->data);
		print_data(tmp_b->data);
		printf("\n");
		if (tmp_a->data != NULL)
			tmp_a = tmp_a->next;
		if (tmp_b->data != NULL)
			tmp_b = tmp_b->next;
	}
	printf("-   -\na   b");
}