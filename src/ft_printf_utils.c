/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:18 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/11 12:57:13 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

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
