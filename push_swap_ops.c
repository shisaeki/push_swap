/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:46 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/03 18:57:17 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_node *initial_node)
{
    t_node  *first_node;
    t_node  *second_node;

    if (initial_node->next == initial_node)
        return ;
    first_node = initial_node->next;
    if (first_node->next == initial_node)
        return ;
    second_node = first_node->next;
    initial_node->next = second_node;
    first_node->prev = second_node;
    first_node->next = second_node->next;
    second_node->prev = initial_node;
    second_node->next = first_node;
}

void    rotate(t_node *initial_node)
{
    t_node  *first_node;
    t_node  *second_node;
    t_node  *last_node;

    if (initial_node->next == initial_node)
        return ;
    first_node = initial_node->next;
    second_node = first_node->next;
    last_node = initial_node->prev;
    initial_node->next = second_node;
    initial_node->prev = first_node;
    first_node->next = initial_node;
    first_node->prev = last_node->prev;
    second_node->prev = initial_node;
    last_node->next = first_node;
}

void    rotate_reverse(t_node *initial_node)
{
    t_node  *first_node;
    t_node  *last_node;
    t_node  *prev_last_node;

    if (initial_node->next == initial_node)
        return ;
    first_node = initial_node->next;
    last_node = initial_node->prev;
    prev_last_node = last_node->prev;
    initial_node->next = last_node;
    initial_node->prev = prev_last_node;
    last_node->next = first_node;
    last_node->prev = initial_node;
    first_node->prev = last_node;
    prev_last_node->next = initial_node;
}

void    push(t_node *pop_first_node, t_node *push_first_node)
{
    t_node  *pop_node;
    t_node  *next_pop_node;
    t_node  *next_push_node;

    if (pop_first_node->next == pop_first_node)
        return;
    pop_node = pop_first_node->next;
    next_pop_node = pop_node->next;
    next_push_node = push_first_node-> next;
    pop_first_node->next = next_pop_node;
    next_pop_node->prev = pop_first_node;
    push_first_node->next = pop_node;
    pop_node->prev = push_first_node;
    pop_node->next = next_push_node;
    next_push_node->prev = pop_node;
}

void    sa(t_node *node_a)
{
    swap(node_a);
    printf("sa ");
}

void    sb(t_node *node_b)
{
    swap(node_b);
    printf("sb ");
}

void    ss(t_node *node_a, t_node *node_b)
{
    sa(node_a);
    sb(node_b);
    printf("sa sb ");
}

void    ra(t_node *node_a)
{
    rotate(node_a);
    printf("ra ");
}

void    rb(t_node *node_b)
{
    rotate(node_b);
    printf("rb ");
}

void    rr(t_node *node_a, t_node *node_b)
{
    rotate(node_a);
    rotate(node_b);
    printf("rr ");
}

void    rra(t_node *node_a)
{
    rotate_reverse(node_a);
    printf("rra ");
}

void    rrb(t_node *node_b)
{
    rotate_reverse(node_b);
    printf("rrb ");
}

void    rrr(t_node *node_a, t_node *node_b)
{
    rotate_reverse(node_a);
    rotate_reverse(node_b);
    printf("rrr ");
}

void    pa(t_node *node_b, t_node *node_a)
{
    push(node_b, node_a);
    printf("pa ");
}

void    pb(t_node *node_a, t_node *node_b)
{
    push(node_a, node_b);
    printf("pb ");
}