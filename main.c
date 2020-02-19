#include "./inc/ft_printf.h"
#include "./ft_printf.c"

int            main(int ac, char **av)
{
	int				d = 588;
	int				f = 30;
	char			c = 'a';
	char			*s = "Salut je suis Ben";
	int				x = -2554564;
	int				X = -2554564;
	unsigned		u = 154645468;

//printf("\n '%-5' : mon return = %d\n", ft_printf("\n%-5"));
	printf("| Return : %d", ft_printf("%s.", s));
}
