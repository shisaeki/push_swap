/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:28:46 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/03 18:59:31 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int count, char **str, t_node **node_a, t_node **node_b)
{
	int	i;

	*node_a = init_list();
	*node_b = init_list();
	i = 0;
	while (i < count - 1)
	{
		append_last(*node_a, ft_atoi(str[i + 1]));
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_node	*initial_node_a;
	t_node	*initial_node_b;

	init_stacks(argc, argv, &initial_node_a, &initial_node_b);
	sa(initial_node_a);
	sb(initial_node_b);
	printf("\n");
	print_stacks(initial_node_a, initial_node_b);
}