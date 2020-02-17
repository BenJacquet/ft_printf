
#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// mode = 1 : on utilise la precision
// mode = 0 : on utilise la len
void	ft_putstr_mod(char *str, s_struct *f, int mode)
{
	int	limit;
	int	count;
	int len;

	count = 0;
	len = ft_strlen(str);
	limit = (mode == 1 ? f->precision : len);
	while (str[count] && count < limit)
	{
		ft_putchar(str[count++]);
		f->count++;
	}
}