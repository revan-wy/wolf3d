# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 19:12:59 by revan-wy          #+#    #+#              #
#    Updated: 2018/09/16 10:29:44 by revan-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf
CC = gcc
FLAGS = -Wall -Wextra -Werror
COMP = $(CC) $(FLAGS)
FRAMEWORK = -framework OpenGL \
			-framework AppKit
LIBFT_H = -I ./libft/
LIBS = -L./libft -lft \
	   -lmlx
SRC = calculations.c \
	  graphics.c \
	  keys.c \
	  map_functions.c \
	  wolf.c

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

makelibft:
	make -C libft/

$(NAME): makelibft $(OBJ)
	$(CC) -g $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) $(FRAMEWORK)

%.o: %.c
	$(COMP) -g -c $< $(LIBFT_H) -o $@ $(INCL)

clean: 
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

#to compile object file use:
#	gcc -c -Wall -Werror -Wextra wolf.c

#to compile executable use:
#