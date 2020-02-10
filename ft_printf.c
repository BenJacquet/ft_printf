
#include "header.h"
#include "parsing.c"
#include "buffer.c"
#include "print.c"
#include "utils.c"

int ft_identifier(char c, s_struct *f, int mode)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
    {
        f->specifier = 1;
		return (1);
    }
	else if (c == '-' || (c >= '0' && c <= '9') || c == '.' || c == '*')
	{
		if (c == '*')
			f->wild = 1;
		return (1);
	}
	return (0);
}

const char *ft_percent(const char *format, va_list va_lst, s_struct *f)
{
    int     i;

    i = 0;
    format++;
    while (ft_identifier(*format, f, 1) && *format)
    {
        i++;
        if (f->first == 1)
            f->specifier ? format = ft_flag(format, va_lst, f) : format;
        ft_specifier(format++, va_lst, f);
    }
}

int ft_process(const char *format, va_list va_lst, s_struct *f)
{
    int count;
    char buffer[4096];

    count = 0;
    ft_bzero(buffer, 4096);
    while (*format)
    {
        if (*format == '%')
        {
            format = ft_percent(format, va_lst, f);
            f->specifier ? : ft_char();
            ft_initialize(f);
        }
        else
    }
}

int ft_printf(const char *format, ...)
{
    va_list va_lst;
    s_struct f;
    int count;

    count = 0;
    ft_initialize(&f);
    va_start(va_lst, format);
    count = ft_process(format, va_lst, &f);
    va_end(va_lst);
    return (count);
}
