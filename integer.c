#include "ft_printf.h"

static void	print_sign(int number, int plu, int spc)
{
	if (number < 0)
		ft_putchar('-');
	else if (plu)
		ft_putchar('+');
	else if (spc)
		ft_putchar(' ');
}

static void	minus(int arg, int len, char *in, t_f *f)
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

static void	precision(int arg, int len, char *in, t_f *f)
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

static void	zero_and_else(int arg, char *in, int tmplen, t_f *f)
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

int			integer(t_f *f, va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	int		arg;

	arg = va_arg(ap, int);
	in = ft_itoa((int)ft_abs(arg));
	len = (int)ft_strlen(in);
	tmplen = (f->plu || f->spc || arg < 0) ? f->wid - len - 1 : f->wid - len;
	if (tmplen <= 0)
	{
		print_sign(arg, f->plu, f->spc);
		tmplen = f->pre - len;
		ft_putcharn('0', tmplen);
		ft_putstr(in);
	}
	else if (f->min)
		minus(arg, len, in, f);
	else if (f->dot)
		precision(arg, len, in, f);
	else
		zero_and_else(arg, in, tmplen, f);
	return (0);
}
