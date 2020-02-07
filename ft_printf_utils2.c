/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:18 by jabenjam          #+#    #+#             */
/*   Updated: 2019/11/18 19:43:48 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int n)
{
	return (n < 0 ? (int64_t)-n : (int64_t)n);
}

int			ft_strlen(char *str)
{
	int			len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char		*ft_strrev(char *str)
{
	int			i;
	int			len;
	char		tmp;

	len = 0;
	while (str[len])
		len += 1;
	i = -1;
	while (++i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
	str[i] = '\0';
	return (str);
}

int			ft_ilen(unsigned int n, int mode)
{
	int64_t		len;
	int64_t		nb;

	len = 0;
	if (n < 0)
		len++;
	nb = ft_abs(n);
	while (nb > mode)
	{
		nb = nb / mode;
		len++;
	}
	return (len + 1);
}

int		ft_mini_atoi(const char *str)
{
	int64_t		res;
	int			i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		res = (res * 10) + (str[i++] - '0');
	return (res);
}
