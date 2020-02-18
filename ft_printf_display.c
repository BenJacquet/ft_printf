/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:18 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/18 17:17:35 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
** Mode = 0 : On utilise la len
** Mode = 1 : On utilise la precision
*/
void		ft_putstr_mod(char *str, t_data *f, int mode)
{
	int		limit;
	int		count;
	int		len;

	count = 0;
	len = ft_strlen(str);
	limit = (mode == 1 ? f->precision : len);
	while (str[count] && count < limit)
	{
		ft_putchar(str[count++]);
		f->count++;
	}
}