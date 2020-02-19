/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:14:13 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 12:08:07 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_select(va_list va_lst, t_data *f)
{
	if (f->specifier == 'c')
		ft_char(va_arg(va_lst, int), f);
	else if (f->specifier == 's')
		ft_string(va_arg(va_lst, char *), f);
	else if (f->specifier == 'p')
		ft_pointer(va_arg(va_lst, unsigned long long), f);
	else if (f->specifier == 'd' || f->specifier == 'i')
		ft_int(va_arg(va_lst, int), f);
	else if (f->specifier == 'u')
		ft_uint_hex(va_arg(va_lst, unsigned int), f);
	else if (f->specifier == 'x')
		ft_uint_hex(va_arg(va_lst, unsigned int), f);
	else if (f->specifier == 'X')
		ft_uint_hex(va_arg(va_lst, unsigned int), f);
	else if (f->specifier == '%')
		f->count += ft_putchar('%');
	return (0);
}

void		t_initialize(t_data *f)
{
	f->specifier = 0;
	f->width = 0;
	f->precision = -1;
	f->left = 0;
	f->pointer = 0;
	f->zero = 0;
	f->count = 0;
	f->len = 0;
}

int			ft_process(const char *format, va_list va_lst, t_data *f)
{
	int		count;

	count = 0;
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format++);
		else
		{
			format = ft_get_flag(++format, va_lst, f);
			ft_select(va_lst, f);
			count += f->count;
			ft_initialize(f);
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	va_lst;
	t_data	f;
	int		count;

	count = 0;
	ft_initialize(&f);
	va_start(va_lst, format);
	count = ft_process(format, va_lst, &f);
	va_end(va_lst);
	return (count);
}
