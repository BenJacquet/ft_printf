
#include "ft_printf.h"

int			ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_address(void *adr, s_struct *f)
{
	int		len;
	int		i;

	len = ft_ilen((uint64_t)adr, 16);
	f->adress = 2;
	return (ft_hex((uint64_t)adr, f, 0) + 2);
}
