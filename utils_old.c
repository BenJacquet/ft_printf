
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
	s = buffer + 4095;
	*s = '\0';
	return (ft_hex2(nb, s, f, caps));
}