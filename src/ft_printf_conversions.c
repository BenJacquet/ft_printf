/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:13:36 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/02 19:32:20 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_atoi(const char *str)
{
	unsigned int	result;
	int				i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
	}
	return (result);
}

void				ft_itoa(int n, char *buffer)
{
	int				i;
	int				sign;
	unsigned int	nb;

	i = 0;
	sign = n < 0 ? 1 : 0;
	nb = ft_abs(n);
	while (nb >= 10)
	{
		buffer[i++] = nb % 10 + '0';
		nb /= 10;
	}
	buffer[i++] = nb % 10 + '0';
	if (sign)
		buffer[i++] = '-';
	buffer[i] = '\0';
	ft_strrev(buffer);
}

void				ft_uitoa(unsigned int nb, char *buffer)
{
	int				i;

	i = 0;
	while (nb >= 10)
	{
		buffer[i++] = nb % 10 + '0';
		nb /= 10;
	}
	buffer[i++] = nb % 10 + '0';
	buffer[i] = '\0';
	ft_strrev(buffer);
}

void				ft_uitoa_base(unsigned int nb, char *buffer)
{
	char			*hex;
	int				i;

	i = 0;
	hex = "0123456789abcdef";
	while (nb >= 16)
	{
		buffer[i++] = hex[(nb % 16)];
		nb /= 16;
	}
	buffer[i++] = hex[(nb % 16)];
	buffer[i] = '\0';
	ft_strrev(buffer);
}

void				ft_ulltoa_base(unsigned long long nb, char *buffer)
{
	char			*hex;
	int				i;

	i = 0;
	hex = "0123456789abcdef";
	while (nb >= 16)
	{
		buffer[i++] = hex[(nb % 16)];
		nb /= 16;
	}
	buffer[i++] = hex[(nb % 16)];
	buffer[i] = '\0';
	ft_strrev(buffer);
}
