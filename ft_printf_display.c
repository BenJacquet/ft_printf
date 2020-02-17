
#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr_mod(char *str, s_struct *f, int mode)
{
	int	limit;

	limit = (mode == 1 ? f->precision : f->len);
	while (str[f->count] && f->count < limit)
		ft_putchar(str[f->count++]);
}