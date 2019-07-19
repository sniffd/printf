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
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt && g_f->dot && !g_f->pre) - (g_f->pre - len * (g_f->pre - 1 > 0)) * (g_f->pre > len + (g_f->okt && arg) * 2);
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		x_minus(arg, len, in);
	else if (g_f->dot)
		x_precision(arg, len, in);
	else
		x_zero_and_else(in, tmplen, arg);
	free(in);
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
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt && g_f->dot && !g_f->pre) - (g_f->pre - 1 * (g_f->pre - 1 > 0)) * (g_f->pre > len + (g_f->okt && arg) * 2);
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		x_minus(arg, len, in);
	else if (g_f->dot)
		x_precision(arg, len, in);
	else
		x_zero_and_else(in, tmplen, arg);
	free(in);
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
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt && g_f->dot && !g_f->pre) - (g_f->pre - 1 * (g_f->pre - 1 > 0)) * (g_f->pre > len + (g_f->okt && arg) * 2);
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		x_minus(arg, len, in);
	else if (g_f->dot)
		x_precision(arg, len, in);
	else
		x_zero_and_else(in, tmplen, arg);
	free(in);
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
	tmplen = g_f->wid - (len * (!(!arg && g_f->dot && !g_f->pre) && (len > g_f->wid || !g_f->dot))) + (!arg && g_f->dot && !g_f->pre) - (g_f->f == 'p'|| (g_f->okt && arg)) * 2 - (!arg && (g_f->okt || g_f->f == 'p') && g_f->dot && !g_f->pre) - (g_f->pre - 1 * (g_f->pre - 1 > 0)) * (g_f->pre > len + ((g_f->okt || g_f->f == 'p') && arg) * 2);
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		x_minus(arg, len, in);
	else if (g_f->dot)
		x_precision(arg, len, in);
	else
		x_zero_and_else(in, tmplen, arg);
	free(in);
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
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt && g_f->dot && !g_f->pre) - (g_f->pre - 1 * (g_f->pre - 1 > 0)) * (g_f->pre > len + (g_f->okt && arg) * 2);
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		x_minus(arg, len, in);
	else if (g_f->dot)
		x_precision(arg, len, in);
	else
		x_zero_and_else(in, tmplen, arg);
	free(in);
}
