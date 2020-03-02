/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_detectors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:53:23 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/02 13:57:15 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_detect_intmin(char *buffer)
{
	int		i;
	char	*int_min;

	i = 0;
	int_min = "-2147483648";
	while (buffer[i] && int_min[i])
	{
		if (buffer[i] != int_min[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
