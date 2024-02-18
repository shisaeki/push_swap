/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:11 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 15:34:44 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int data, int rank)
{
	t_node	*new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->rank = rank;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

void	insert_at_end(t_node **head, int data, int rank)
{
	t_node *new_node;
	t_node *tmp;

	new_node = create_node(data, rank);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}
