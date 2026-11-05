# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ******** <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 14:05:28 by ********          #+#    #+#              #
#    Updated: 2026/10/31 22:19:51 by ********         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
HEADERS = . 
FLAGS = -Wall -Wextra -Werror -I $(HEADERS)
SRCS = operators1.c operators2.c operators3.c ft_algorithm_sort.c ft_bucket_sort.c \
		ft_algorithm_helper.c ft_main_helper.c ft_main_utils.c ft_utils_global.c main.c
OBJECTS = $(SRCS:.c=.o)
LIBFT = libft.a
LIBFTPRINTF = libftprintfd.a
NAME = push_swap

.DEFAULT: all

.PHONY: help clean fclean re all

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(FLAGS) -o $@ $^

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
