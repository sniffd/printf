#include "ft_printf.h"

void	x_char(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_strtolower(ft_itoa_base(arg, 16));
	len = (int)ft_strlen(in);
	f->wid = f->okt && arg && ((--f->wid || 1) && (!--f->wid || 1)) ?
			f->wid : f->wid;
	tmplen = f->wid - len;
	if (tmplen <= 0)
	{
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

void	x_short(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_strtolower(ft_itoa_base(arg, 16));
	len = (int)ft_strlen(in);
	f->wid = f->okt && arg && ((--f->wid || 1) && (!--f->wid || 1)) ?
			f->wid : f->wid;
	tmplen = f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		oktotorp(arg, len);
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

void	x_int(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_strtolower(ft_itoa_base(arg, 16));
	len = (int)ft_strlen(in);
	f->wid = f->okt && arg && ((--f->wid || 1) && (!--f->wid || 1)) ?
			f->wid : f->wid;
	tmplen = f->wid - len;
	if (tmplen <= 0)
	{
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

void	x_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_strtolower(ft_itoa_base(arg, 16));
	len = (int)ft_strlen(in);
	f->wid = f->okt && arg && ((--f->wid || 1) && (!--f->wid || 1)) ?
			f->wid : f->wid;
	tmplen = f->wid - len;
	if (tmplen <= 0)
	{
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

void	x_long_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_strtolower(ft_itoa_base(arg, 16));
	len = (int)ft_strlen(in);
	f->wid = f->okt && arg && ((--f->wid || 1) && (!--f->wid || 1)) ?
			f->wid : f->wid;
	tmplen = f->wid - len;
	if (tmplen <= 0)
	{
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
