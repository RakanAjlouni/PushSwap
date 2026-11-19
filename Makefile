NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC			= -I./inc -I./libft

LIB_DIR		= ./libft
LIB			= $(LIB_DIR)/libft.a

SRCS		= src/main.c src/parsing/parsing.c src/stack/stack_init.c \
			  src/stack/stack_utils.c src/operations/swap_ops.c \
			  src/operations/operations.c src/operations/push_ops.c \
			  src/operations/rotate_ops.c src/operations/rev_rotate_ops.c \
			  src/algorithms/adaptive.c src/algorithms/simple.c \
			  src/algorithms/medium.c src/algorithms/complex.c \
			  src/algorithms/algo_utils.c src/utils/error_free.c \
			  src/utils/bench.c src/parsing/parsing_utils.c \

OBJS		= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
