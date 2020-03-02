/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:58:28 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/02 13:57:18 by jabenjam         ###   ########.fr       */
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
	if (!nb)
		return (1);
	if (nb < 0)
		len++;
	if (nb == -2147483648 || nb == 2147483647)
		return (len += 10 + 1);
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
	if (nb == 4294967295)
		return (11);
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
	if (nb >= 9223372036854775807)
		return (21);
	while (nb > base)
	{
		nb /= base;
		len++;
	}
	return (len + 1);
}
