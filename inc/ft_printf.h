/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:30 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/20 17:52:27 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	int			specifier;
	int			width;
	int			precision;
	int			space;
	int			left;
	int			zero;
	int			pointer;
	int			len;
	int			count;
}				t_data;

/*
**------CORE FUNCTIONS----------------------------------------------------
*/

void			ft_select(va_list va_lst, t_data *f);
void			ft_initialize(t_data *f);
int				ft_process(const char *format, va_list va_lst);
int				ft_printf(const char *format, ...);

/*
**------SPECIFIER FUNCTIONS------------------------------------------------
*/

void			ft_char(int c, t_data *f);
void			ft_string(char *str, t_data *f);
void			ft_padding_str(char *str, t_data *f);
void			ft_pointer(unsigned long long pointer, t_data *f);
void			ft_padding_pointer(char *str, t_data *f);
void			ft_int(int nb, t_data *f);
void			ft_int_next(char *buffer, t_data *f, int sign);
void			ft_padding_int(char *buffer, t_data *f, int sign);
void			ft_uint_hex(unsigned int nb, t_data *f);
void			ft_uint_hex_next(char *buffer, t_data *f);
void			ft_padding_uint_hex(char *buffer, t_data *f);
void			ft_width(t_data *f, int mode);

/*
**------PARSING FUNCTIONS------------------------------------------------
*/

int				ft_get_specifier(const char *id, t_data *f, int i);
int				ft_get_precision(const char *id, va_list va_lst, t_data *f, int i);
int				ft_get_width(const char *id, va_list va_lst, t_data *f, int i);
int				ft_get_flag(const char *id, va_list va_lst, t_data *f, int i);
int				ft_get_space(char c, t_data *f);

/*
**------CONVERSION FUNCTIONS-----------------------------------------------
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int nb);
char			*ft_uitoa(unsigned int nb);
char			*ft_uitoa_base(unsigned int nb);
char			*ft_ulltoa_base(unsigned long long nb);
int				ft_abs(int n);
char			*ft_toupper(char *str);
char			*ft_strrev(char *str);

/*
**------LENGTH FUNCTIONS----------------------------------------------------
*/

int				ft_strlen(const char *str);
int				ft_ilen(int nb, int base);
int				ft_uilen(unsigned int nb, unsigned int base);
int				ft_ulllen(unsigned long long nb, unsigned int base);

/*
**------DETECTOR FUNCTIONS---------------------------------------------------
*/

int				ft_isspace(int c);
int				ft_isdigit(int c);

/*
**------PRINT FUNCTIONS-------------------------------------------------------
*/

int				ft_putchar(char c);
void			ft_putstr_mod(char *str, t_data *f, int mode);

#endif
