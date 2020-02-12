#include "ft_printf.h"

int            main(int ac, char **av)
{
	int				d = 588;
	int				f = 30;
	char			c = 'a';
	char			*s = "salut je suis ben";
	int				x = -2554564;
	int				X = -255456412;
	unsigned		u = 154645468;

//	printf("\n '%-5' : mon return = %d\n", ft_printf("\n%-5"));
	printf("| Return : %d", ft_printf("%s.", s));
}