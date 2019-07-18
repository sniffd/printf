#include "ft_printf.h"

void	o_char(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg && !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of + (g_f->pre > 0 && g_f->of && !arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		o_minus(arg, len, in);
	else if (g_f->dot)
		o_precision(arg, len, in);
	else
		o_zero_and_else(in, tmplen);
}

void	o_short(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg && !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of + (g_f->pre > 0 && g_f->of && !arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		o_minus(arg, len, in);
	else if (g_f->dot)
		o_precision(arg, len, in);
	else
		o_zero_and_else(in, tmplen);
}

void	o_int(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg && !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of + (g_f->pre > 0 && g_f->of && !arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		o_minus(arg, len, in);
	else if (g_f->dot)
		o_precision(arg, len, in);
	else
		o_zero_and_else(in, tmplen);
}

void	o_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg && !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of + (g_f->pre > 0 && g_f->of && !arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		o_minus(arg, len, in);
	else if (g_f->dot)
		o_precision(arg, len, in);
	else
		o_zero_and_else(in, tmplen);
}

void	o_long_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg && !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of + (g_f->pre > 0 && g_f->of && !arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		o_minus(arg, len, in);
	else if (g_f->dot)
		o_precision(arg, len, in);
	else
		o_zero_and_else(in, tmplen);
}
