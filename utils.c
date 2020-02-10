void ft_initialize(s_struct *f)
{
    f->ccount = 0;
    f->first = 1;
    f->specifier = 0;
	f->width = 0;
	f->padding = ' ';
	f->prec = 0;
	f->negative = 0;
	f->left = 0;
	f->adress = 0;
	f->zero = 0;
	f->wild = 0;
	f->handle = 0;
}

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	else
		ft_memset(s, 0, n);
}