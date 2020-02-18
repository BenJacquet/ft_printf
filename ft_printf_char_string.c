/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:09 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/18 14:14:13 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *str, s_struct *f)
{
	if (!str)
		str = "(null)";
	f->len = ft_strlen(str);
	if (f->precision >= 0 && f->precision > f->len)
		f->precision = f->len;
	if (f->left)
		ft_padding_str(str, f);
	if (f->precision >= 0)
		ft_width(f, 1);
	else
		ft_width(f, 0);
	if (!f->left)
		ft_padding_str(str, f);
}

void	ft_char(int c, s_struct *f)
{
	if (f->left)
		ft_putchar(c);
	ft_width(f);
	if (!f->left)
		ft_putchar(c);
	f->count++; // on compte le char a print
}