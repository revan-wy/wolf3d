# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 18:47:55 by revan-wy          #+#    #+#              #
#    Updated: 2018/08/09 18:24:00 by revan-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
COMP = $(CC) $(FLAGS)
LIBFT_H = -I ./
SRC = ft_atoi.c \
      ft_absval.c \
      ft_bzero.c \
      ft_getwcntsd.c \
      ft_intswap.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_itoa.c \
      ft_lstadd.c \
      ft_lstdel.c \
      ft_lstdelone.c \
      ft_lstiter.c \
      ft_lstmap.c \
      ft_lstnew.c \
      ft_logrndup.c \
      ft_memalloc.c \
      ft_memccpy.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memdel.c \
      ft_memmove.c \
      ft_memset.c \
      ft_putchar.c \
      ft_putchar_fd.c \
      ft_putendl.c \
      ft_putendl_fd.c \
      ft_putnbr.c \
      ft_putnbr_fd.c \
      ft_putstr.c \
      ft_putstr_fd.c \
      ft_strcat.c \
      ft_strchr.c \
      ft_strclr.c \
      ft_strcmp.c \
      ft_strcpy.c \
      ft_strdel.c \
      ft_strdup.c \
      ft_strequ.c \
      ft_striter.c \
      ft_striteri.c \
      ft_strjoin.c \
      ft_strlcat.c \
      ft_strlen.c \
      ft_strmap.c \
      ft_strmapi.c \
      ft_strncat.c \
      ft_strnew.c \
      ft_strnequ.c \
      ft_strncmp.c \
      ft_strncpy.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strsplit.c \
      ft_strstr.c \
      ft_strsub.c \
      ft_strtrim.c \
      ft_tolower.c \
      ft_toupper.c \
      ft_xttpy.c \
      get_next_line.c

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

%.o: %.c
	$(COMP) -c $< $(LIBFT_H) -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

exec:
	gcc $(FLAGS) -L. $(NAME) main.c

local:
	gcc $(FLAGS) main.c

norm:
	norminette *.c *.h
