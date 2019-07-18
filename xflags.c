#include "ft_printf.h"

void	x_minus(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	tmplen = g_f->pre - len;
	if (tmplen <= 0)
	{
		oktotorp(arg);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->okt))
			g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt && g_f->dot && !g_f->pre);
		addcharn(' ', tmplen);
	}
	else
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = g_f->wid - g_f->pre;
		addcharn(' ', tmplen);
	}
}

void	x_precision(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	if (g_f->pre >= len)
		tmplen = g_f->wid - g_f->pre + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && g_f->dot && !g_f->pre);
	else
		tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->okt && g_f->dot && !g_f->pre && !arg) * 2 - (g_f->okt && arg) * 2;
	if (tmplen <= 0)
	{
		oktotorp(arg);
		tmplen = g_f->pre - len - g_f->okt;
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		oktotorp(arg);
		tmplen = g_f->pre - len - g_f->okt;
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void x_zero_and_else(char *in, int tmplen, unsigned long long arg)
{
	if (g_f->zer && !(g_f->dot))
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		oktotorp(arg);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}
