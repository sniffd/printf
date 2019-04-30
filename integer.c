#include "ft_printf.h"

int	int_char(t_f *f, va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	int		arg;

	arg = (char)va_arg(ap, int);
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

int	int_short(t_f *f, va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	int		arg;

	arg = (short)va_arg(ap, int);
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

int	int_int(t_f *f, va_list ap)
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

int	int_long(t_f *f, va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	long	arg;

	arg = va_arg(ap, long);
	in = ft_itoa((long)ft_abs(arg));
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

int	int_long_long(t_f *f, va_list ap)
{
	char		*in;
	int			tmplen;
	int			len;
	long long	arg;

	arg = va_arg(ap, long long);
	in = ft_itoa(ft_abs(arg));
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
