#include "ft_printf.h"

// mode 0 = aucune precision
// mode 1 = precision existante
// si "%p" = on compte deux char de moins
void	ft_width(s_struct *f, int mode)
{
	int	limit;

	limit = (mode == 1 ? f->precision : f->len);
	limit += (f->pointer == 1 ? 2 : 0);
    while (f->width - limit > 0)
    {
	    if (f->zero)
		    ft_putchar('0');
    	else
	    	ft_putchar(' ');
	    f->width--;
	    f->count++;
    }
}

void ft_padding(char *str, s_struct *f)
{
	if (f->pointer) // ajout du "0x" si il s'agit d'un pointeur
		ft_putstr_mod("0x", f, 0);
	if (f->precision >= 0)
	{
		ft_width(f, 0);
		ft_putstr_mod(str, f, 1); // si precision on l'utilise au lieu de len
	}
	else if (f->precision < 0)
		ft_putstr_mod(str, f, 0); // si aucune precision on utilise la len
}