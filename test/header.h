#ifndef HEADER_H

# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct			s_struct
{
	int		count;
	int		first;
    int		specifier;
	int		width;
	int		prec;
	int		wild;
	int		left;
	int		zero;
	int		space;
	int		negative;
	int		adress;
	int		handle;
	char	padding;
}						s_struct;

int				ft_strlen(char *str);
int				ft_mini_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_abs(int n);
char			*ft_strrev(char *str);
int				ft_ilen(unsigned int n, int mode);
int				ft_char(char c);
void			ft_adjust(s_struct *f, int mode, int len);
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