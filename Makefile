NAME = libftprintf.a

SRC = ft_printf.c\
	ft_printf_display.c\
	ft_printf_utils.c\
	ft_printf_utils2.c\

OBJ = $(SRC:.c=.o)

INC = ft_printf.h

CC = gcc


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

.PHONY : all clean fclean re bonus
