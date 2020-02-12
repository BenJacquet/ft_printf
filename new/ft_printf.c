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

int ft_identifier(char c, s_struct *f, int mode)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else if (c == '-' || (c >= '0' && c <= '9') || c == '.' || c == '*')
	{
		if (c == '*')
			f->wild = 1;
		return (1);
	}
	else if (c == '+' && mode == 1)
	{
		f->plus = 1;
		return (1);
	}
	return (0);
}

void ft_adjust(s_struct *f, int mode, int len)
{
	if (mode == 0)
	{
		if ((f->wid == 0 || f->wid <= f->prec) && f->prec > 0)
		{
			f->wid = f->prec;
			f->zero = 1;
		}
	}
	else if (mode == 1)
	{
		if (f->handle == 1 && f->prec == 0)
			f->null = 1;
		else if (f->wid == 0 && f->prec > 0 && len > f->prec)
			f->wid = len;
	}
}

const char *ft_flag2(const char *id, va_list va_lst, s_struct *f)
{
	if (*id == '.')
	{
		f->handle = 1;
		id++;
		while (*id == '*' || ((*id >= '0' && *id <= '9') && *id))
		{
			if (*id == '*')
			{
				f->prec = va_arg(va_lst, int);
				id++;
				break;
			}
			f->prec *= 10;
			f->prec += *id - '0';
			id++;
			if (f->prec == 0 && (*id == 's'))
				f->prec = -1;
		}
	}
	f->first = 1;
	return (id);
}

const char *ft_flag(const char *id, va_list va_lst, s_struct *f)
{
	if (*id == '-')
	{
		f->left = 1;
		id++;
	}
	while (*id == '0'  && f->left == 0 && *id)
	{
		f->zero = 1;
		f->pad = '0';
		id++;
	}
	while (*id == '*' || ((*id >= '0' && *id <= '9') && *id))
	{
		if (*id == '*')
		{
			f->wid = va_arg(va_lst, int);
			id++;
			break;
		}
		f->wid *= 10;
		f->wid += *id - '0';
		id++;
	}
	ft_flag2(id, va_lst, f);
	return (id);
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
	f->wid = 0;
	f->plus = 0;
	f->pad = ' ';
	f->prec = 0;
	f->neg = 0;
	f->left = 0;
	f->adress = 0;
	f->zero = 0;
	f->null = 0;
	f->wild = 0;
	f->handle = 0;
	f->first = 0;
}

int ft_process(const char *format, va_list va_lst, s_struct *f)
{
	int count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (ft_identifier(*format, f, 1) && *format)
			{
				if (f->first == 0)
					format = ft_flag(format, va_lst, f);
				count += ft_function(format++, va_lst, f);
			}
			ft_initialize(f);
		}
		else
			count += ft_char(*format++);
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
