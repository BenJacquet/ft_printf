/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:51:47 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 15:04:16 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** Recuperation du specifier
*/

int		ft_get_specifier(const char *id, t_data *f, int i)
{
	if ((id[i] == 'c') || (id[i] == 's') || (id[i] == 'p') ||
		(id[i] == 'd') || (id[i] == 'i') || (id[i] == 'u') ||
		(id[i] == 'x') || (id[i] == 'X') || (id[i] == '%'))
	{
		f->specifier = id[i];
		i++;
	}
	return (i);
}

/*
** Recuperation de la precision
** si il y a une precision on ignore le flag "zero"
*/

int		ft_get_precision(const char *id, va_list va_lst, t_data *f, int i)
{
	if (id[i] == '.')
	{
		i++;
		f->precision = 0;
		if (ft_isdigit(id[i]))
		{
			f->precision = ft_atoi(id + i);
			i += ft_ilen(f->width, 10);
		}
		else if (id[i] == '*')
		{
			f->precision = va_arg(va_lst, int);
			f->precision = (f->precision < 0 ? 0 : f->precision);
			i++;
		}
		if (f->precision > 0)
			f->zero = 0;
	}
	return (ft_get_specifier(id, f, i));
}

/*
** Recuperation de la largeur
** si la largeur est negative on active le flag "left"
*/

int		ft_get_width(const char *id, va_list va_lst, t_data *f, int i)
{
	if (ft_isdigit(id[i]))
	{
		f->width = ft_atoi(id + i);
		while (ft_isdigit(id[i]))
			i++;
	}
	else if (id[i] == '*')
	{
		f->width = va_arg(va_lst, int);
		i++;
	}
	if (f->width < 0)
	{
		f->left = 1;
		f->width = (unsigned int)ft_abs(f->width);
	}
	return (ft_get_precision(id, va_lst, f, i));
}

/*
** Recuperation des flags "zero" et "left"
*/

int		ft_get_flag(const char *id, va_list va_lst, t_data *f, int i)
{
	if (id[i] == '0')
	{
		f->zero = 1;
		i++;
	}
	if (id[i] == '-')
	{
		f->left = 1;
		i++;
	}
	return (ft_get_width(id, va_lst, f, i));
}
