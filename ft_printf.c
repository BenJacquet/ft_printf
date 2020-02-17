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
//#include "ft_printf_utils.c"
#include "ft_printf_display.c"
#include "ft_printf_utils2.c"

void	ft_test_struct(s_struct *f)
{
	printf("f->width = %d", f->width);
	printf("\nf->precision = %d", f->precision);
	printf("\nf->specifier = '%c'", f->specifier);
	printf("\nf->left = %d", f->left);
	printf("\nf->zero = %d", f->zero);
	printf("\nf->pointer = %d", f->pointer);
}

const char *ft_specifier(const char *id, s_struct *f)
{
	// recuperation du specifier
	if ((*id == 'c') || (*id == 's') || (*id == 'p') ||
		(*id == 'd') || (*id == 'i') || (*id == 'u') ||
		(*id == 'x') || (*id == 'X') || (*id == '%'))
	{
		f->specifier = *id;
		id++;
	}
	return (id);
}

const char *ft_precision(const char *id, va_list va_lst, s_struct *f)
{ // recuperation de la precision
	if (*id == '.')
	{
		id++;
		f->precision = 0;
		if (ft_isdigit(*id))
		{
			f->precision = ft_atoi(id);
			id += ft_ilen(f->width, 10); // idem que width
		}
		else if (*id == '*')
		{
			f->precision = va_arg(va_lst, int);
			f->precision = (f->precision < 0 ? 0 : f->precision);
			id++;
		}
		if (f->precision)
			 f->zero = 0; // si il y a une precision on ignore le flag zero
	}
	return (ft_specifier(id, f));
}

const char *ft_width(const char *id, va_list va_lst, s_struct *f)
{ // recuperation de la largeur
	if (ft_isdigit(*id))
	{
		f->width = ft_atoi(id);
		id += ft_ilen(f->width, 10); // on avance dans id de n char
	}
	else if (*id == '*')
	{
		f->width = va_arg(va_lst, int);
		id++;
	}
	if (f->width < 0)
	{ // si la largeur est negative on active le flag left
		f->left = 1;
		f->width = (unsigned int)ft_abs(f->width);
	}
	return (ft_precision(id, va_lst, f));
}

const char *ft_flag(const char *id, va_list va_lst, s_struct *f)
{ // recuperation des flags "zero" et "left"
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

int ft_select(va_list va_lst, s_struct *f)
{
	if (f->specifier == 'c')
		ft_char(va_arg(va_lst, int), f);
	else if (f->specifier == 's')
		ft_string(va_arg(va_lst, char *), f);
	else if (f->specifier == 'p')
		ft_pointer((void *)va_arg(va_lst, unsigned long long), f);
	else if (f->specifier == 'd' || f->specifier == 'i')
		ft_integer(va_arg(va_lst, int), f, 1);
	else if (f->specifier == 'u')
		ft_uinteger(va_arg(va_lst, int), f, 0);
	else if (f->specifier == 'x')
		ft_hex(va_arg(va_lst, unsigned int), f, 0);
	else if (f->specifier == 'X')
		ft_hex(va_arg(va_lst, unsigned int), f, 1);
	else if (f->specifier == '%')
		f->count += ft_putchar('%');
	return (0);
}

void ft_initialize(s_struct *f)
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

int ft_process(const char *format, va_list va_lst, s_struct *f)
{
	int		count;

	count = 0;
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format++);
		else
		{
			format = ft_flag(++format, va_lst, f);
//			ft_test_struct(f);
			ft_select(va_lst, f);
			count += f->count;
			ft_initialize(f);
		}
	}
	// implementer affichage du buffer et ajout de count += strlen(buffer)
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list 	va_lst;
	s_struct 	f;
	int			count;

	count = 0;
	ft_initialize(&f);
	va_start(va_lst, format);
	count = ft_process(format, va_lst, &f);
	va_end(va_lst);
	return (count);
}