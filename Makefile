NAME = libftprintf.a

SRC = ft_printf_core.c\
	ft_printf_parsing.c\
	ft_printf_char_string.c\
	ft_printf_pointer.c\
	ft_printf_int.c\
	ft_printf_uint_hex.c\
	ft_printf_width.c\
	ft_printf_utils.c\
	ft_printf_length.c\
	ft_printf_conversions.c\
	ft_printf_display.c\

OBJ = $(SRC:.c=.o)

INC = ft_printf.h

CC = gcc -Wall -Werror -Wextra


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
	gcc -g ft_printf.c main.c
	rm -rf ~/WIP/a.out
	rm -rf ~/WIP/a.out.dSYM/
	cp a.out ~/WIP/
	cp -rf a.out.dSYM ~/WIP/

.PHONY : all clean fclean re
