# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 19:12:59 by revan-wy          #+#    #+#              #
#    Updated: 2018/09/11 18:33:52 by revan-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf
CC = gcc
FLAGS = -Wall -Wextra -Werror
COMP = $(CC) $(FLAGS)
#INCL = -I ./
FRAMEWORK = -framework OpenGL \
			-framework AppKit
LIBFT_H = -I ./libft/
LIBS = -L./libft -lft \
	   -lmlx
SRC = wolf.c

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

makelibft:
	make -C libft/

$(NAME): makelibft $(OBJ)
	$(CC) -g $(WFLAGS) $(OBJ) $(LIBS) -o $(NAME) $(FRAMEWORK)

%.o: %.c
	$(COMP) -g -c $< $(LIBFT_H) $(WOLF3D_H) -o $@ $(INCL)

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