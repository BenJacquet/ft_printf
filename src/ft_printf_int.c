/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:27 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 15:32:40 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_padding_int(char *buffer, t_data *f, int sign)
{
	if (sign == 1 && f->precision >= 0)
		ft_putchar('-');
	if (f->precision >= 0)
	{
		f->zero = 1;
		f->width = f->precision - 1;
		ft_width(f, 0);
	}
	ft_putstr_mod(buffer, f, 0);
}

void		ft_int_next(char *buffer, t_data *f, int sign)
{
	if (f->left)
		ft_padding_int(buffer, f, sign);
	if (f->precision >= 0 && (size_t)f->precision < f->len)
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

/*
** CP : Si nb = 0 et aucune precision on print la largeur si il y en a une
*/

void		ft_int(int nb, t_data *f)
{
	char	*buffer;
	int		sign;

	sign = (nb < 0 ? 1 : 0);
	if (!f->precision && !nb && f->width)
		return (ft_width(f, 0));
	if (nb < 0 && (f->precision >= 0 || f->zero))
	{
		if (f->zero && f->precision == -1)
			ft_putstr_mod("-", f, 0);
		nb = ft_abs(nb);
		f->zero = 1;
		f->width--;
	}
	buffer = ft_itoa(nb);
	f->len = ft_strlen(buffer);
	ft_int_next(buffer, f, sign);
	free(buffer);
}

/*
** (ligne 32) : si ça ne marche pas changer f->precision en size_t
** (ligne 63) : modifier "f->width--"  si il y a un bug
*/
