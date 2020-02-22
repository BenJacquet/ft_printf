#include "./inc/ft_printf.h"
#include "ft_printf.c"

int            main(int ac, char **av)
{
	int				d = -2147483648;
	int				f = 30;
	char			c = 'a';
	char			*s = "salut je suis ben";
	int				x = -2554564;
	int				X = -2554564;
	unsigned int	u = 4294967294;
	int				i = 212312;
	//printf("\n '0.10u' : mon  return = %d\n", ft_printf("\n%0.10u", u));
	//printf("\n '0.10u' : vrai return = %d\n", printf("\n%0.10u", u));
//	printf("| Return : %d", ft_printf("\n%x", x));
//  ft_printf("\n%100s", s);
//	printf("---------------------------------------------------------\n");
//	printf("\ntrue = %d\n", ft_printf("mine = %50.30d\n", d));
//	printf("\ntrue = %d\n", printf("true = %50.30d\n", d));
	printf("\nmine = %d\n", ft_printf("I8AnzU%0dncj%X%X%s", 0, -14044880, -2147483647, "uxDhZ1Ak6SvkHpHXfNe92YRh9Zv"));
	printf("\ntrue = %d\n", printf("I8AnzU%0dncj%X%X%s", 0, -14044880, -2147483647, "uxDhZ1Ak6SvkHpHXfNe92YRh9Zv"));
}