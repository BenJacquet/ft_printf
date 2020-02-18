/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:30 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/18 15:06:51 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct			s_struct
{
	int		specifier;
	int		width;
	int		precision;
	int		left;
	int		zero;
	int		pointer;
	int		len;
	int		count;
}						s_struct;

/*
**------CORE FUNCTIONS---------------------------------------------------------
*/

/*
**------PARSING FUNCTIONS------------------------------------------------------
*/

/*
**------CONVERSION FUNCTIONS---------------------------------------------------
*/

/*
**------UTILITY FUNCTIONS-------------------------------------------------------
*/

/*
**------PRINT FUNCTIONS--------------------------------------------------------
*/

#endif
