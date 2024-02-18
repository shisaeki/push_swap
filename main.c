/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:30:13 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 15:52:30 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*node_a;
	t_node	*node_b;
	int		*arr;
	int		*sorted;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	sorted = (int *)malloc(sizeof(int) * (argc - 1));
	for (int i = 0; i < argc - 1; i++)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		sorted[i] = ft_atoi(argv[i + 1]);
	}
	bubble_sort(sorted, argc - 1);
	node_a = NULL;
	node_b = NULL;
	init_stack(&node_a, arr, sorted, argc - 1);
	print_stacks(node_a, node_b);
	push_swap_seven_or_more(&node_a, &node_b, argc - 1);
	free(arr);
	free(sorted);
}