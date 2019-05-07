#include "ft_printf.h"

int	o_char(t_f *f, va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	tmplen = (f->plu || f->spc) ? f->wid - len - 1 : f->wid - len;
	oktotorp(f, arg, in, len);
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		ft_putcharn('0', tmplen);
		if (!(!f->pre && !arg))
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

int	o_short(t_f *f, va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	tmplen = (f->plu || f->spc) ? f->wid - len - 1 : f->wid - len;
	oktotorp(f, arg, in, len);
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		ft_putcharn('0', tmplen);
		if (!(!f->pre && !arg))
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

int	o_int(t_f *f, va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	tmplen = (f->plu || f->spc) ? f->wid - len - 1 : f->wid - len;
	oktotorp(f, arg, in, len);
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		ft_putcharn('0', tmplen);
		if (!(f->dot == 1 && !f->pre && !arg))
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

int	o_long(t_f *f, va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	tmplen = (f->plu || f->spc) ? f->wid - len - 1 : f->wid - len;
	oktotorp(f, arg, in, len);
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		ft_putcharn('0', tmplen);
		if (!(!f->pre && !arg))
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

int	o_long_long(t_f *f, va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	tmplen = (f->plu || f->spc) ? f->wid - len - 1 : f->wid - len;
	oktotorp(f, arg, in, len);
	if (tmplen <= 0)
	{
		tmplen = f->pre - len;
		ft_putcharn('0', tmplen);
		if (!(!f->pre && !arg))
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