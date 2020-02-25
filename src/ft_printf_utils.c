/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:18 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/25 12:56:26 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char		*ft_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char		*ft_strrev(char *str)
{
	int beg;
	int end;
	int tmp;

	beg = 0;
	end = ft_strlen(str);
	while (beg < (end / 2))
	{
		tmp = str[end - 1 - beg];
		str[end - 1 - beg] = str[beg];
		str[beg] = tmp;
		beg++;
	}
	return (str);
}
