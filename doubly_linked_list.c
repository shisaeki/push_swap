/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:56:56 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/03 18:40:57 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node*	init_list()
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = NULL;
	node->next = node;
	node->prev = node;

	return (node);
}

void	append_last(t_node *initial_node, int value)
{
	t_node*	new_node;
	int*	data_ptr;

	new_node = (t_node *)malloc(sizeof(t_node));
	data_ptr = (int *)malloc(sizeof(int));
	if (!new_node || !data_ptr)
		return ;
	*data_ptr = value;
	new_node->data = data_ptr;
	new_node->next = initial_node;
	new_node->prev = initial_node->prev;
	initial_node->prev->next = new_node;
	initial_node->prev = new_node;
}

void	append_first(t_node *initial_node, int value)
{
	t_node*	new_node;
	t_node*	first_node;
	int*	data_ptr;

	new_node = (t_node *)malloc(sizeof(t_node));
	data_ptr = (int *)malloc(sizeof(int));
	if (!new_node || !data_ptr)
		return ;
	first_node = initial_node->next;
	*data_ptr = value;
	initial_node->next = new_node;
	new_node->data = data_ptr;
	new_node->next = first_node;
	new_node->prev = initial_node;
	first_node->prev = new_node;
}

void	delete_last(t_node *initial_node)
{
	t_node	*last_node;

	if (initial_node->next == initial_node)
		return ;
	last_node = initial_node->prev;
	initial_node->prev = last_node->prev;
	last_node->prev->next = initial_node;
	free(last_node->data);
	free(last_node);
}

void	delete_first(t_node *initial_node)
{
	t_node	*first_node;

	if (initial_node->next == initial_node)
		return ;
	first_node = initial_node->next;
	initial_node->next = first_node->next;
	first_node->next->prev = initial_node;
	free(first_node->data);
	free(first_node);
}

int		lstsize(t_node *initial_node)
{
	t_node*	current_node;
	int		count;

	current_node = initial_node->next;
	count = 0;
	while (current_node->data != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}

void	free_list(t_node *initial_node)
{
	t_node	*current;
	t_node	*next;

	current = initial_node->next;
	while (current->data != NULL)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	free(current->data);
	free(current);
}