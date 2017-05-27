# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavagner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 11:37:19 by mavagner          #+#    #+#              #
#    Updated: 2016/12/01 18:51:10 by abourgeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/main.c \
	  srcs/ft_map.c \
	  srcs/ft_check.c \
	  srcs/ft_add.c \
	  srcs/ft_bzero.c \
	  srcs/ft_putchar.c \
	  srcs/ft_memalloc.c \
	  srcs/ft_strnew.c \
	  srcs/ft_strlen.c \
	  srcs/ft_strcpy.c \
	  srcs/ft_strcat.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strjoin_free.c\
	  srcs/ft_strsplit.c\
	  srcs/ft_print_fillit.c\
	  srcs/ft_putendl.c\
	  srcs/ft_isalpha.c\
	  srcs/ft_resolve_tetris.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(CFLAGS) -o $(NAME) -lft -L./libft -I./libft $(OBJ)

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean
