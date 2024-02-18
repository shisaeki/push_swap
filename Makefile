# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 00:18:46 by shinsaeki         #+#    #+#              #
#    Updated: 2024/02/18 16:00:24 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = ./push_swap/
OPERATIONS = ./operations/
UTILS = ./utils/
INCLUDES = ./includes/push_swap.h

SRCS = main.c \
	$(OPERATIONS)ops_swap.c \
	$(OPERATIONS)ops_push.c \
	$(OPERATIONS)ops_rotate.c \
	$(OPERATIONS)ops_reverse_rotate.c \
	$(PUSH_SWAP)push_swap_six_or_less.c \
	$(PUSH_SWAP)push_swap_three_or_less.c \
	$(PUSH_SWAP)push_swap_seven_or_more.c \
	$(PUSH_SWAP)push_swap_utils.c \
	$(UTILS)doubly_linked_list.c \
	$(UTILS)sort_utils.c \
	$(UTILS)ft_utils.c \

TARGET = push_swap_exec

all: $(TARGET)
	$(CC) -o $(TARGET) -I $(INCLUDES) $(SRCS)
clean:
	rm -f $(TARGET)
re:
	clean all