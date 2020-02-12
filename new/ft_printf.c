/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:14:13 by jabenjam          #+#    #+#             */
/*   Updated: 2019/11/19 16:25:02 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.c"
#include "ft_printf_display.c"
#include "ft_printf_utils2.c"

void ft_adjust(s_struct *f, int mode, int len)
{
	if (mode == 0)
	{
		if ((f->width == 0 || f->width <= f->prec) && f->prec > 0)
		{
			f->width = f->prec;
			f->zero = 1;
		}
	}
	else if (mode == 1)
	{
		if (f->handle == 1 && f->prec == 0)
			f->null = 1;
		else if (f->width == 0 && f->prec > 0 && len > f->prec)
			f->width = len;
	}
}

const char *ft_precision(const char *id, va_list va_lst, s_struct *f)
{ // recuperation de la precision
	if (*id == '.')
	{
		f->handle = 1;
		id++;
		if (ft_isdigit(*id))
			f->prec = ft_atoi(id);
		else if (*id == '*')
		{
			f->prec = va_arg(va_lst, int);
			f->prec = (f->prec < 0 ? 0 : f->prec);
			id++;
		}
	}
	return (id);
}

const char *ft_width(const char *id, va_list va_lst, s_struct *f)
{ // recuperation de la largeur
	if (ft_isdigit(*id))
		f->width = ft_atoi(id);
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
	return (ft_precision(id, va_lst, f));
}

const char *ft_flag(const char *id, va_list va_lst, s_struct *f)
{ // recuperation des flags "zero" et "left";
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
	return (ft_width(id, va_lst, f));
}

int ft_function(const char *id, va_list va_lst, s_struct *f)
{
	if (*id == '%')
		return (ft_printc('%', f, 1));
	else if (*id == 'c')
		return (ft_printc(va_arg(va_lst, int), f, 1));
	else if (*id == 's')
		return (ft_print(va_arg(va_lst, char *), f, 1));
	else if (*id == 'p')
		return (ft_address((void *)va_arg(va_lst, uint64_t), f));
	else if (*id == 'd' || *id == 'i')
		return (ft_integer(va_arg(va_lst, int), f, 1));
	else if (*id == 'u')
		return (ft_integer(va_arg(va_lst, int), f, 0));
	else if (*id == 'x')
		return (ft_hex(va_arg(va_lst, unsigned int), f, 0));
	else if (*id == 'X')
		return (ft_hex(va_arg(va_lst, unsigned int), f, 1));
	return (0);
}

void ft_initialize(s_struct *f)
{
	f->width = 0;
	f->prec = 0;
	f->neg = 0;
	f->left = 0;
	f->adress = 0;
	f->zero = 0;
	f->null = 0;
	f->wild = 0;
	f->handle = 0;
}

int ft_process(const char *format, va_list va_lst, s_struct *f)
{
	int		count;
	char	buffer[4096];

	count = 0;
	ft_bzero(buffer, 4096);
	while (*format)
	{
		if (*format != '%')
			ft_char(*format++);
		else
			format = ft_flag(format, va_lst, f);
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list va_lst;
	int count;
	s_struct f;

	count = 0;
	ft_initialize(&f);
	va_start(va_lst, format);
	count = ft_process(format, va_lst, &f);
	va_end(va_lst);
	return (count);
}
