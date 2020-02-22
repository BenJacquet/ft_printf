/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:14:13 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/22 06:09:27 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ft_printf.h"

#include "./src/ft_printf_char_string.c"
#include "./src/ft_printf_conversions.c"
#include "./src/ft_printf_display.c"
#include "./src/ft_printf_int.c"
#include "./src/ft_printf_length.c"
#include "./src/ft_printf_parsing.c"
#include "./src/ft_printf_pointer.c"
#include "./src/ft_printf_uint_hex.c"
#include "./src/ft_printf_utils.c"
#include "./src/ft_printf_width.c"

void		ft_select(va_list va_lst, t_data *f)
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
		ft_percent(f);
}

void		ft_initialize(t_data *f)
{
	f->specifier = 0;
	f->width = 0;
	f->precision = -1;
	f->space = 0;
	f->left = 0;
	f->pointer = 0;
	f->zero = ' ';
	f->count = 0;
	f->len = 0;
}

int			ft_process(const char *format, va_list va_lst)
{
	int		count;
	int		i;
	t_data	f;

	count = 0;
	i = 0;
	while (format[i])
	{
		ft_initialize(&f);
		if (format[i] != '%')
			count += ft_putchar(format[i++]);
		else
		{
			i = ft_get_flag(format, va_lst, &f, ++i);
			ft_select(va_lst, &f);
			count += f.count;
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	va_lst;
	int		count;

	count = 0;
	va_start(va_lst, format);
	count = ft_process(format, va_lst);
	va_end(va_lst);
	return (count);
}
