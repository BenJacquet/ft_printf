/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:27 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/22 06:08:45 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_padding_int(char *buffer, t_data *f, int sign, int nb)
{
	if (sign == 1 && f->precision >= 0 && nb != -2147483648)
		f->count += ft_putchar('-');
	if (f->precision >= 0)
		ft_width(f, f->precision - 1, f->len - 1, '0');
	ft_putstr_mod(buffer, f, 0);
}

void		ft_int_next(char *buffer, t_data *f, int sign, int nb)
{
	if (f->left)
		ft_padding_int(buffer, f, sign, nb);
	if (f->precision >= 0 && f->precision < f->len)
		f->precision = f->len;
	if (f->precision >= 0)
	{
		f->width -= f->precision;
		ft_width(f, f->width, 0, ' ');
		if (buffer[0] == '-')
		{
			ft_putchar('-');
			f->width--;
			buffer++;
			sign = 0;
		}
	}
	else
		ft_width(f, f->width, f->len, f->zero);
	if (!f->left)
		ft_padding_int(buffer, f, sign, nb);
}

void		ft_int(int nb, t_data *f)
{
	char	*buffer;
	int		sign;

	sign = (nb < 0 ? 1 : 0);
	if (f->space && !sign)
		f->count += ft_putchar(' ');
	if (!f->precision && !nb)
		return (ft_width(f, f->width, 0, ' '));
	if (nb < 0 && (f->precision >= 0 || f->zero == '0'))
	{
		if (f->zero == '0' && f->precision == -1 && nb != -2147483648)
		{
			f->count += ft_putchar('-');
			sign = 0;
		}
		nb = ft_abs(nb);
		f->zero = '0';
		f->width--;
	}
	buffer = ft_itoa(nb);
	f->len = ft_strlen(buffer);
	ft_int_next(buffer, f, sign, nb);
	free(buffer);
}

/*
** (ligne 32) : si ça ne marche pas changer f->precision en size_t
** (ligne 63) : modifier "f->width--"  si il y a un bug
*/
