/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:30 by jabenjam          #+#    #+#             */
/*   Updated: 2019/11/18 19:54:08 by jabenjam         ###   ########.fr       */
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
	int		dot;
	int		left;
	int		zero;
	int		pointer;
	int		count;
}						s_struct;

int				ft_strlen(char *str);
int				ft_atoi(const char *str);
int				ft_isspace(int c);
int				ft_isdigit(int c);
const char 		*ft_specifier(const char *id, s_struct *f);
int				ft_abs(int n);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strrev(char *str);
int				ft_ilen(unsigned int n, int base);
int				ft_putchar(char c);
int				ft_string(char *str, s_struct *f);
int				ft_decimal(int n, s_struct *f);
int				ft_hex(uint64_t n, s_struct *f, int caps);
int				ft_address(void *adr, s_struct *f);
int				ft_identifier(char c, s_struct *f, int mode);
void			ft_adjust(s_struct *f, int mode, int len);
const char*		ft_flag(const char *id, va_list va_lst, s_struct *f);
const char*		ft_flag2(const char *id, va_list va_lst, s_struct *f);
int				ft_function(const char *id, va_list va_lst, s_struct *f);
int				ft_process(const char *format, va_list va_lst, s_struct *f);
int				ft_printf(const char *format, ...);

#endif
