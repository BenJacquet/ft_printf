/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:38 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/20 14:54:53 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_padding_pointer(char *str, t_data *f)
{
	ft_putstr_mod("0x", f, 2);
	if (f->precision >= 0)
	{
		ft_putstr_mod(str, f, 1);
//		ft_width(f, f->precision, f->len , ' ');
	}
	else
		ft_putstr_mod(str, f, 0);
}

void		ft_pointer(unsigned long long pointer, t_data *f)
{
	char	*buffer;

	if (pointer == 0 && f->precision == 0)
	{
		ft_putstr_mod("0x", f, 2);
		ft_width(f, f->width, 0, '0');
		return;
	}
	buffer = ft_ulltoa_base(pointer);
	f->len = ft_strlen(buffer);
	if (f->precision < f->len)
		f->precision = f->len;
	if (f->left)
		ft_padding_pointer(buffer, f);
	ft_width(f, f->width, f->len + 2, ' ');
	if (!f->left)
		ft_padding_pointer(buffer, f);
	free(buffer);
}
