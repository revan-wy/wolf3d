# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 19:12:59 by revan-wy          #+#    #+#              #
#    Updated: 2018/09/03 17:34:02 by revan-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
CFLAGS = -c
SFLAGS = -framework SDL2 -F ~/Library/Frameworks
WFLAGS = -Wall -Wextra -Werror
FLAGS = $(CFLAGS) $(SFLAGS) $(WFLAGS)
COMP = $(CC) $(CFLAGS) $(WFLAGS)
INCL = -I ~/.brew/include
FRAMEWORK = -framework OpenGL \
			-framework AppKit
LIBFT_H = -I ./libft/
LIBS = -L./libft -lft \
	   -lmlx
SRC = instantcg.c \
	main.c

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

makelibft:
	make -C libft/

$(NAME): makelibft $(OBJ)
	$(COMP) $(OBJ) $(LIBS) -o $(NAME) $(FRAMEWORK)

%.o: %.c
	$(COMP) -c $< $(LIBFT_H) $(WOLF3D_H) -o $@ $(INCL)

clean: 
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all