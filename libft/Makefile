# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/07 16:39:16 by rajlouni          #+#    #+#              #
#    Updated: 2026/10/19 12:16:50 by rajlouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isdigit.c ft_putchar_fd.c ft_putendl_fd.c ft_substr.c ft_strncmp.c\
	   ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strlen.c ft_strlcpy.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all
