#include "ft_printf.h"

void	ft_pointer(unsigned long long pointer, s_struct *f)
{
	char    *buffer;

	if (pointer == 0 && f->precision == 0)
	{
		ft_putstr_mod("0x", f, 0);
		ft_width(f, 0);
	}
	buffer = ft_hex(pointer, f, 0);
	f->len = ft_strlen(buffer);
	if ((size_t)f->precision < ft_strlen(buffer))
		f->precision = f->len;
	if (f->left)
		ft_padding(buffer, f);
	ft_width(f, 0);
	if (!f->left)
		ft_padding(buffer, f);
	free(buffer);
}