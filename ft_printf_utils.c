
#include "ft_printf.h"

int		ft_empty(s_struct *f)
{
	int		i;

	i = 0;
	if (f->width > 0)
	{
		while (i < f->width)
		{
//			write(1, &f->pad, 1);
			i++;
		}
	}
	return (i);
}

int		ft_print2(char *s, s_struct *f, int len, int mode)
{
	int		i;

	i = 0;

	if (mode == 1 && f->precision < len && f->precision)
		len = f->precision;
	if (*s && mode == 1 && f->precision > 0 && f->width == 0)
	{
		write(1, s, len);
		i += len;
	}
	else if (*s && f->precision != -1)
	{
		write(1, s, len);
		i += len;
	}
	else if (f->precision == -1)
		f->width = len;
	while (f->width > 0)
	{
//		i += ft_char(f->pad);
		f->width--;
	}
	return (i);
}

int		ft_print(char *s, s_struct *f, int mode)
{
	int		i;
	int		len;

	if (s == NULL && mode == 1)
		s = "(null)";
	else if (!s)
		return (ft_empty(f));
	len = ft_strlen(s);
	i = 0;
	ft_adjust(f, mode, len);
	if (mode == 1 && (f->null == 1 || (f->handle == 1 && f->width == 0 &&
			f->precision == 0)))
		return (0);
	if (f->width > 0)
	{
		if (len >= f->width && mode == 1 && f->handle == 1)
		{
			len = f->width; //le bug se produit ici !!!
			f->width = 0;
		}
		else
			f->width = (f->precision > 0 && mode == 1 ? len : f->width - len);
	}
//	f->pad = (f->zero == 1 ? '0' : ' ');
	while (f->left != 1 && f->width > 0)
	{
//		i += ft_char(f->pad);
		f->width--;
	}
	return (i + (ft_print2(s, f, len, mode)));
}

int		ft_integer2(unsigned int n, char *s, s_struct *f)
{
	int		i;

	i = 0;
	ft_adjust(f, 0, ft_ilen(n, 10));
	while (n)
	{
		*--s = (n % 10) + '0';
		n /= 10;
	}
	while (f->precision > ft_strlen(s) && ft_strlen(s) < f->width)
		*--s = '0';
	if (f->neg)
	{
		if (f->width && f->zero)
		{
			i += ft_putchar('-');
			f->width--;
		}
		else
			*--s = '-';
	}
	return (i + (ft_print(s, f, 0)));
}

int		ft_integer(int n, s_struct *f, int sign)
{
	char	buffer[4096];
	char	*s;
	unsigned int nb;

	nb = n;
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (ft_print(s, f, 0));
	}
	else if (sign == 1 && n < 0)
	{
		f->neg = 1;
		nb = -n;
	}
	s = buffer + 4095;
	*s = '\0';
	return (ft_integer2(nb, s, f));
}

int		ft_hex2(uint64_t n, char *s, s_struct *f, int caps)
{
	int		i;
	char	*hex;
	char	*hex2;

	i = 0;
	hex = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	ft_adjust(f, 0, ft_ilen(n, 16));
	while (n)
	{
		*--s = (caps == 1 ? hex2[(n % 16)]: hex[(n % 16)]);
		n /= 16;
	}
	if (f->pointer == 2)
	{
		*--s = 'x';
		*--s = '0';
	}
	while (f->precision > ft_strlen(s) && ft_strlen(s) < f->width)
		*--s = '0';
	return (i + (ft_print(s, f, 0)) - f->pointer);
}

int		ft_hex(uint64_t n, s_struct *f, int caps)
{
	char		buffer[4096];
	char		*s;
	uint64_t	nb;

	nb = n;
	if (!n)
	{
		if (f->pointer == 2)
		{
			buffer[0] = '0';
			buffer[1] = 'x';
			buffer[2] = '0';
			buffer[3] = '\0';
			return (ft_print(buffer, f, 0) - 2);
		}
		else
		{
			buffer[0] = '0';
			buffer[1] = '\0';
		}
		return (ft_print(buffer, f, 0));
	}
	s = buffer + 4095;
	*s = '\0';
	return (ft_hex2(nb, s, f, caps));
}

int		ft_char(int c, s_struct *f, int mode)
{
	char s[2];

	s[0] = (char)c;
	s[1] = '\0';

	if (f->width > 0 && c == 0)
	{
		if (f->left == 1)
			return (f->width);
		f->width = f->width - 1;
	}
	if (f->width == 0)
		return (ft_putchar(c));
	else
		return (c == 0 ? ft_print(s, f, 1) + 1 : ft_print(s, f, 1));
}

int			ft_pointer(void *adr, s_struct *f)
{
	int		len;
	int		i;

	len = ft_ilen((uint64_t)adr, 16);
	f->pointer = 2;
	return (ft_hex((uint64_t)adr, f, 0) + 2);
}