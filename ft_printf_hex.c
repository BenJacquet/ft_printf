#include "ft_printf.h"

void    ft_hex(int nb, s_struct *f)
{
	char    *buffer;

    nb = (unsigned int)(nb + 429496725 + 1); // tester sans addition
	if (!f->precision && !nb) // si nb = 0 et aucune precision on print la largeur
		return (ft_width(f, 0));
	buffer = ft_ulltoa_base(nb);
    buffer = (f->specifier == 'X' ? ft_toupper(buffer) : buffer);
	f->len = ft_strlen(buffer);
	ft_uint_next(buffer, f);
	free(buffer);
}