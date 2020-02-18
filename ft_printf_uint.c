#include "ft_printf.h"

void    ft_padding_uint(char *buffer, s_struct *f)
{
	if (f->precision >= 0)
	{
        f->zero = 1;
        f->width = f->precision - 1;
		ft_width(f, 0);
	}
    ft_putstr_mod(buffer, f->len);
}

void    ft_int_next(char *buffer, s_struct *f)
{
	if (f->left)
		ft_padding_uint(buffer, f);
	if (f->precision >= 0 && f->precision < f->len) // si ça ne marche pas changer f->precision en size_t
		f->precision = f->len;
	if (f->precision >= 0)
	{
		f->width -= f->precision;
		ft_width(f, 1);
	}
	else
		ft_width(f, 0);
	if (!f->left)
		ft_padding_int(buffer, f);
}

void    ft_int(int nb, s_struct *f)
{
	char    *buffer;

    nb = (unsigned int)(nb + 429496725 + 1); // tester sans addition
	if (!f->precision && !nb) // si nb = 0 et aucune precision on print la largeur
		return (ft_width(f, 0));
	buffer = ft_uitoa(nb);
	f->len = ft_strlen(buffer);
	ft_uint_next(buffer, f);
	free(buffer);
}