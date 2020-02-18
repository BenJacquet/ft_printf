/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:58:28 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/18 16:53:26 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int					ft_ilen(unsigned int nb, int base)
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

int					ft_ulllen(unsigned long long nb, int base)
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