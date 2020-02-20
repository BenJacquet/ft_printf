/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:18 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/20 15:06:17 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
** Mode = 0 : On utilise la len
** Mode = 1 : On utilise la precision
** Mode = 2 : On print le "0x"
*/

void		ft_putstr_mod(char *str, t_data *f, int mode)
{
	int		limit;

	if (mode == 2)
		f->len = 2;
	limit = (mode == 1 ? f->precision : f->len);
	if (str)
	{
		write(1, str, limit);
		f->count += limit;
	}
}
