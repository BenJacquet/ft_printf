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

.PHONY : all clean fclean re bonus
