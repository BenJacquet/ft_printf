/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:51:47 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/02 13:57:19 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
			while (ft_isdigit(id[i]))
				i++;
		}
		else if (id[i] == '*')
		{
			f->precision = va_arg(va_lst, int);
			f->precision = (f->precision < 0 ? -1 : f->precision);
			i++;
		}
		if (f->precision > 0)
			f->zero = ' ';
	}
	return (ft_get_specifier(id, f, i));
}

/*
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
		f->zero = ' ';
		f->width = (unsigned int)ft_abs(f->width);
	}
	return (ft_get_precision(id, va_lst, f, i));
}

int		ft_get_space(char c, t_data *f)
{
	if (c == ' ')
	{
		f->space = 1;
		return (1);
	}
	return (0);
}

int		ft_get_flag(const char *id, va_list va_lst, t_data *f, int i)
{
	if (ft_get_space(id[i], f))
		i++;
	if (id[i] == '0')
	{
		f->zero = '0';
		i++;
	}
	if (ft_get_space(id[i], f))
		i++;
	if (id[i] == '-')
	{
		f->left = 1;
		i++;
	}
	if (ft_get_space(id[i], f))
		i++;
	return (ft_get_width(id, va_lst, f, i));
}
