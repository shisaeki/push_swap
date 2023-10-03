/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:40:56 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/03 18:55:44 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_node
{
	int				*data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

int		ft_atoi(const char *str);
t_node*	init_list();
void	append_last(t_node *initial_node, int value);
void	append_first(t_node *initial_node, int value);
void	delete_last(t_node *initial_node);
void	delete_first(t_node *initial_node);
int		lstsize(t_node *initial_node);
void	free_list(t_node *initial_node);
void	print_data(int *data);
void	print_stacks(t_node* initial_node_a, t_node* initial_node_b);
void    swap(t_node *initial_node);
void    rotate(t_node *initial_node);
void    rotate_reverse(t_node *initial_node);
void    push(t_node *pop_first_node, t_node *push_first_node);
void    sa(t_node *node_a);
void    sb(t_node *node_b);
void    ss(t_node *node_a, t_node *node_b);
void    ra(t_node *node_a);
void    rb(t_node *node_b);
void    rr(t_node *node_a, t_node *node_b);
void    rra(t_node *node_a);
void    rrb(t_node *node_b);
void    rrr(t_node *node_a, t_node *node_b);
void    pa(t_node *node_b, t_node *node_a);
void    pb(t_node *node_a, t_node *node_b);

#endif