/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:38 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 11:49:27 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pointer(unsigned long long pointer, t_data *f)
{
	char	*buffer;

	if (pointer == 0 && f->precision == 0)
	{
		ft_putstr_mod("0x", f, 0);
		ft_width(f, 0);
	}
	buffer = ft_ulltoa_base(pointer);
	f->len = ft_strlen(buffer);
	if ((size_t)f->precision < ft_strlen(buffer))
		f->precision = f->len;
	if (f->left)
		ft_padding_str(buffer, f);
	ft_width(f, 0);
	if (!f->left)
		ft_padding_str(buffer, f);
	free(buffer);
}
