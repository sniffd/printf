#include "ft_printf.h"

void	print_sign(long long number, int plu, int spc)
{
	if (number < 0)
		g_vector = ft_vector(g_vector, "-", 5, 0);
	else if (plu)
		g_vector = ft_vector(g_vector, "+", 5, 0);
	else if (spc)
		g_vector = ft_vector(g_vector, " ", 5, 0);
}

void	minus(long long arg, int len, char *in)
{
	int	tmplen;

	print_sign(arg, g_f->plu, g_f->spc);
	tmplen = g_f->pre - len;
	oktotorp(arg, len);
	if (tmplen <= 0)
	{
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 :
			g_f->wid - len;
		addcharn(' ', tmplen);
	}
	else
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - g_f->pre - 1 :
			g_f->wid - g_f->pre;
		addcharn(' ', tmplen);
	}
}

void	precision(long long arg, int len, char *in)
{
	int	tmplen;

	if (g_f->pre >= len)
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - g_f->pre - 1 :
			g_f->wid - g_f->pre;
	else
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 :
			g_f->wid - len;
	if (tmplen <= 0 && oktotorp(arg, len))
	{
		tmplen = g_f->pre - len;
		print_sign(arg, g_f->plu, g_f->spc);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		tmplen = g_f->pre - len;
		print_sign(arg, g_f->plu, g_f->spc);
		oktotorp(arg, len);
		addcharn('0', tmplen);
		in = !(!g_f->pre && !arg) ? in : " ";
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	zero_and_else(long long arg, char *in, int tmplen)
{
	int	len;

	len = (int)ft_strlen(in);
	if (g_f->zer && !(g_f->dot))
	{
		print_sign(arg, g_f->plu, g_f->spc);
		oktotorp(arg, len);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		print_sign(arg, g_f->plu, g_f->spc);
		oktotorp(arg, len);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	integer(va_list ap)
{
	if (g_f->hh)
		int_char(ap);
	else if (g_f->h)
		int_short(ap);
	else if (g_f->ll)
		int_long_long(ap);
	else if (g_f->l)
		int_long(ap);
	else
		int_int(ap);
}
