/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:18 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/04 20:54:21 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_putchar(int c)
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
	int		i;

	limit = (mode == 1 ? f->precision : f->len);
	i = 0;
	if (mode == 2)
		limit = 2;
	while (i < limit)
		f->count += ft_putchar(str[i++]);
}
