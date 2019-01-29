# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 17:53:10 by cpoirier          #+#    #+#              #
#    Updated: 2019/01/29 17:14:28 by cpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_v

SRCS = srcs/main.c			\
	   srcs/key_hook.c		\
	   srcs/loop.c			\
	   srcs/sort.c			\
	   srcs/ope.c			\

HDRS = includes/push_v.h	\

LIBFT = libft

OBJS = $(SRCS:%.c=%.o)

CFLAGS = #-Wall -Wextra -Werror -O2 -flto

CC = gcc

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -I./includes -I /usr/local/includes $(LIBFT)/libft.a -lpthread -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
