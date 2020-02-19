/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:58:28 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 16:17:20 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_strlen(const char *str)
{
	int				len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

int					ft_ilen(int nb, int base)
{
	unsigned int	len;

	len = 0;
	if (nb < 0)
		len++;
	nb = ft_abs(nb);
	while (nb > base)
	{
		nb /= base;
		len++;
	}
	return (len + 1);
}

int					ft_uilen(unsigned int nb, unsigned int base)
{
	unsigned int	len;

	len = 0;
	nb = ft_abs(nb);
	while (nb > base)
	{
		nb /= base;
		len++;
	}
	return (len + 1);
}

int					ft_ulllen(unsigned long long nb, unsigned int base)
{
	unsigned int	len;

	len = 0;
	while (nb > base)
	{
		nb /= base;
		len++;
	}
	return (len + 1);
}
