# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 13:55:10 by jabenjam          #+#    #+#              #
#    Updated: 2020/03/11 12:59:28 by jabenjam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c\
	src/ft_printf_parsing.c\
	src/ft_printf_char_string.c\
	src/ft_printf_pointer.c\
	src/ft_printf_int.c\
	src/ft_printf_uint_hex.c\
	src/ft_printf_width.c\
	src/ft_printf_utils.c\
	src/ft_printf_conversions.c\
	src/ft_printf_detectors.c\
	src/ft_printf_display.c\

OBJ = $(SRC:.c=.o)

INC = -I /inc/

CC = gcc

DBG= -fsanitize=address

CFLAGS = -c -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

debug :
	gcc -g src/ft_printf.c main.c
	rm -rf ~/WIP/a.out
	rm -rf ~/WIP/a.out.dSYM/
	cp a.out ~/WIP/
	cp -rf a.out.dSYM ~/WIP/

bonus : all

.PHONY : all clean fclean re bonus debug
