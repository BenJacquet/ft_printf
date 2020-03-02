/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:45 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/02 13:57:21 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_padding_uint(char *buffer, t_data *f)
{
	if (f->precision >= 0)
		ft_width(f, f->precision - 1, f->len - 1, '0');
	ft_putstr_mod(buffer, f, 0);
}

void	ft_uint_next(char *buffer, t_data *f)
{
	if (f->left)
		ft_padding_uint(buffer, f);
	if (f->precision >= 0 && f->precision < f->len)
		f->precision = f->len;
	if (f->precision >= 0)
	{
		f->width -= f->precision;
		ft_width(f, f->width, 0, ' ');
	}
	else
		ft_width(f, f->width, f->len, f->zero);
	if (!f->left)
		ft_padding_uint(buffer, f);
}

/*
** CP : Si nb = 0 et aucune precision on print la largeur si il y en a une
*/

void	ft_uint_hex(unsigned int nb, t_data *f)
{
	char	*buffer;

	if (!f->precision && !nb)
		return (ft_width(f, f->width, 0, ' '));
	if (f->specifier == 'u')
		buffer = ft_uitoa(nb);
	else
		buffer = ft_uitoa_base((unsigned int)nb);
	buffer = (f->specifier == 'X' ? ft_toupper(buffer) : buffer);
	f->len = ft_strlen(buffer);
	ft_uint_next(buffer, f);
	free(buffer);
}
