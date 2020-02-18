//#include "ft_printf.h"
#include <stdio.h>

int            main(int ac, char **av)
{
	int				d = 588;
	int				f = 1;
	char			c = 'a';
	char			*s = "salut je suis ben";
	int				x = 2554564;
	int				X = -2554564;
	unsigned		u = 154645468;

//	printf("\n '%-5' : mon return = %d\n", ft_printf("\n%-5"));
//	printf("\nReturn : %d", ft_printf("\n%015.*%", x));
//	ft_printf("bla%%%");
	printf("%X\n", X);
}