#include "ft_printf.h"

void    ft_padding_int(char *buffer, s_struct *f, int sign)
{
	if (sign == 1 && f->precision >= 0)
		ft_putchar('-');
	if (f->precision >= 0)
	{
        f->zero = 1;
        f->width = f->precision - 1;
		ft_width(f, 0);
	}
    ft_putstr_mod(buffer, f->len);
}

void    ft_int_next(char *buffer, s_struct *f, int sign)
{
	if (f->left)
		ft_padding_int(buffer, f, sign);
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
		ft_padding_int(buffer, f, sign);
}

void    ft_int(int nb, s_struct *f)
{
	char    *buffer;
	int     sign;

	sign = (nb < 0 ? 1 : 0); // stockage du signe
	if (!f->precision && !nb) // si nb = 0 et aucune precision on print la largeur
		return (ft_width(f, 0));
	if (nb < 0 && (f->precision >= 0 || f->zero))
	{
		if (f->zero && f->precision == -1)
			ft_putstr_mod("-", 0);
		nb = ft_abs(nb);
		f->zero = 1;
		f->width--; //on compte le signe;
		f->count++;
	}
	buffer = ft_itoa(nb);
	f->len = ft_strlen(buffer);
	ft_int_next(buffer, f, sign);
	free(buffer);
}
