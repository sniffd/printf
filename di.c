#include "ft_printf.h"

void	print_sign(long long number, int plu, int spc)
{
	if (number < 0)
		ft_putchar('-');
	else if (plu)
		ft_putchar('+');
	else if (spc)
		ft_putchar(' ');
}

void	minus(long long arg, int len, char *in, t_f *f)
{
	int	tmplen;

	print_sign(arg, f->plu, f->spc);
	tmplen = f->pre - len;
	if (tmplen <= 0)
	{
		ft_putstr(in);
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - len - 1 :
			f->wid - len;
		ft_putcharn(' ', tmplen);
	}
	else
	{
		ft_putcharn('0', tmplen);
		ft_putstr(in);
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
			f->wid - f->pre;
		ft_putcharn(' ', tmplen);
	}
}

void	precision(long long arg, int len, char *in, t_f *f)
{
	int	tmplen;

	if (f->pre >= len)
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
			f->wid - f->pre;
	else
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - len - 1 :
			f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		print_sign(arg, f->plu, f->spc);
		ft_putcharn('0', tmplen);
		ft_putstr(in);
	}
	else
	{
		ft_putcharn(' ', tmplen);
		tmplen = f->pre - len;
		print_sign(arg, f->plu, f->spc);
		ft_putcharn('0', tmplen);
		ft_putstr(in);
	}
}

void	zero_and_else(long long arg, char *in, int tmplen, t_f *f)
{
	if (f->zer && !(f->dot))
	{
		print_sign(arg, f->plu, f->spc);
		ft_putcharn('0', tmplen);
		ft_putstr(in);
	}
	else
	{
		ft_putcharn(' ', tmplen);
		print_sign(arg, f->plu, f->spc);
		ft_putstr(in);
	}
}

int		integer(t_f *f, va_list ap)
{
	if (f->hh)
		int_char(f, ap);
	else if (f->h)
		int_short(f, ap);
	else if (f->ll)
		int_long_long(f, ap);
	else if (f->l)
		int_long(f, ap);
	else
		int_int(f, ap);
	return (0);
}
