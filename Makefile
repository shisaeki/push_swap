# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 00:18:46 by shinsaeki         #+#    #+#              #
#    Updated: 2024/02/18 01:18:47 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -g main.c doubly_linked_list.c push_swap_utils.c sort_utils.c push_swap_ops_swap.c push_swap_ops_push.c push_swap_ops_rotate.c push_swap_ops_reverse_rotate.c push_swap_six_or_less.c push_swap_three_or_less.c push_swap_seven_or_more.c
clean:
	rm -f a.out
re:
	clean all