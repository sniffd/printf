#include "ft_printf.h"
#include <stdio.h>

void	int_char(va_list ap)
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
		addcharn('0', tmplen);
		if (!(!f->pre && !arg))
			vector = ft_vector(vector, in, 5, 0);
	}
	else if (f->min)
		minus(arg, len, in);
	else if (f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	int_short(va_list ap)
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
		addcharn('0', tmplen);
		if (!(!f->pre && !arg))
			vector = ft_vector(vector, in, 5, 0);
	}
	else if (f->min)
		minus(arg, len, in);
	else if (f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	int_int(va_list ap)
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
		addcharn('0', tmplen);
		if (!(!f->pre && !arg))
			vector = ft_vector(vector, in, 5, 0);
	}
	else if (f->min)
		minus(arg, len, in);
	else if (f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	int_long(va_list ap)
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
		addcharn('0', tmplen);
		if (!(!f->pre && !arg))
			vector = ft_vector(vector, in, 5, 0);
	}
	else if (f->min)
		minus(arg, len, in);
	else if (f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	int_long_long(va_list ap)
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
		addcharn('0', tmplen);
		if (!(!f->pre && !arg))
			vector = ft_vector(vector, in, 5, 0);
	}
	else if (f->min)
		minus(arg, len, in);
	else if (f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}
