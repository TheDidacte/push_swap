# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 17:53:10 by cpoirier          #+#    #+#              #
#    Updated: 2019/02/05 17:48:05 by cpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRCS = srcs/visual.c		\
	   srcs/key_hook.c		\
	   srcs/loop.c			\
	   srcs/sort.c			\
	   srcs/stack_util.c	\
	   srcs/operations.c	\
	   srcs/perform.c		\
	   srcs/build_ope.c		\
	   srcs/visual_util.c	\
	   srcs/read_util.c		\
	   srcs/basic_case.c	\
	   srcs/quick_sort.c	\

HDRS = includes/push_v.h	\
	   includes/push_swap.h	\

INCLUDES = -g3 -I./includes -I./libft -I./minilibx -I /usr/local/include

LIBFT = libft

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -g3 #-Wall -Wextra -Werror -O2 -flto

CC = gcc

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS) $(LIBFT)/libft.a srcs/push_swap.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $(NAME1) $(OBJS) srcs/push_swap.c $(LIBFT)/libft.a -lmlx -framework OpenGL -framework AppKit
	
#minilibx/libmlx_Linux.a -L/usr/x86_64-linux-gnu -lXext -lX11

$(NAME2): $(OBJS) $(LIBFT)/libft.a srcs/checker.c
	$(CC) $(INCLUDES) -o $(NAME2) $(OBJS) srcs/checker.c $(LIBFT)/libft.a -lmlx -framework OpenGL -framework AppKit

#minilibx/libmlx_Linux.a -L/usr/x86_64-linux-gnu -lXext -lX11

# -framework OpenGL -framework AppKit

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

%.o: %.c $(HDRS)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME1) $(NAME2)

re: fclean all
