


NAME1 = push_swap

NAME2 = checker

SRCS =	srcs/stack_util.c		\
		srcs/operations.c		\
		srcs/perform.c			\

INCLUDES = -I./includes -I./libft

OBJS = $(SRCS:%.c=%.o)

OBJS_FOLDER = objs

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS) srcs/push_swap.c
	gcc $(INCLUDES) -o $(NAME1) $(OBJS) srcs/push_swap.c

$(NAME2): $(OBJS) srcs/checker.c
	gcc $(INCLUDES) -o $(NAME2) $(OBJS) srcs/checker.c

$(OBJS) : $(SRCS) $(OBJS_FOLDER)
	gcc $(INCLUDES) -c $< -o $(OBJS_FOLDER)/$@

$(OBJS_FOLDER):
	mkdir -p $(OBJS_FOLDER)
