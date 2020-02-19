/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:51:47 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 11:49:23 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Recuperation du specifier
*/

const char	*ft_get_specifier(const char *id, t_data *f)
{
	if ((*id == 'c') || (*id == 's') || (*id == 'p') ||
		(*id == 'd') || (*id == 'i') || (*id == 'u') ||
		(*id == 'x') || (*id == 'X') || (*id == '%'))
	{
		f->specifier = *id;
		id++;
	}
	return (id);
}

/*
** Recuperation de la precision
** si il y a une precision on ignore le flag "zero"
*/

const char	*ft__get_precision(const char *id, va_list va_lst, t_data *f)
{
	if (*id == '.')
	{
		id++;
		f->precision = 0;
		if (ft_isdigit(*id))
		{
			f->precision = ft_atoi(id);
			id += ft_ilen(f->width, 10);
		}
		else if (*id == '*')
		{
			f->precision = va_arg(va_lst, int);
			f->precision = (f->precision < 0 ? 0 : f->precision);
			id++;
		}
		if (f->precision > 0)
			f->zero = 0;
	}
	return (ft_get_specifier(id, f));
}

/*
** Recuperation de la largeur
** si la largeur est negative on active le flag "left"
*/

const char	*ft_get_width(const char *id, va_list va_lst, t_data *f)
{
	if (ft_isdigit(*id))
	{
		f->width = ft_atoi(id);
		id += ft_ilen(f->width, 10);
	}
	else if (*id == '*')
	{
		f->width = va_arg(va_lst, int);
		id++;
	}
	if (f->width < 0)
	{
		f->left = 1;
		f->width = (unsigned int)ft_abs(f->width);
	}
	return (ft_get_precision(id, va_lst, f));
}

/*
** Recuperation des flags "zero" et "left"
*/

const char	*ft_get_flag(const char *id, va_list va_lst, t_data *f)
{
	if (*id == '0')
	{
		f->zero = 1;
		id++;
	}
	if (*id == '-')
	{
		f->left = 1;
		id++;
	}
	return (ft_get_width(id, va_lst, f));
}
