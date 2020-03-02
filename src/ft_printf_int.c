/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:27 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/02 19:31:07 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_padding_int(char *buffer, t_data *f, int sign)
{
	if (sign == 1 && f->precision >= 0 && buffer[0] != '-')
		f->count += ft_putchar('-');
	if (f->precision >= 0)
		ft_width(f, f->precision - 1, f->len - 1, '0');
	ft_putstr_mod(buffer, f, 0);
}

void		ft_int_next(char *buffer, t_data *f, int sign)
{
	if (f->left)
		ft_padding_int(buffer, f, sign);
	if (f->precision >= 0 && f->precision < f->len)
		f->precision = f->len;
	if (f->precision >= 0)
	{
		f->width -= f->precision;
		ft_width(f, f->width, 0, ' ');
		if (buffer[0] == '-' && !ft_detect_intmin(buffer))
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
		ft_padding_int(buffer, f, sign);
}

void		ft_int(int nb, t_data *f)
{
	char	buffer[12];
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
		if (nb >= 0)
			f->width--;
	}
	ft_itoa(nb, buffer);
	f->len = ft_strlen(buffer);
	ft_int_next(buffer, f, sign);
}
