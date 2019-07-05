#include "ft_printf.h"

int	oktotorp(unsigned long long arg, int len)
{
	if (g_f->okt || g_f->f == 'p')
	{
		if (g_f->f == 'x' || g_f->f == 'p')
		{
			if (arg || g_f->f == 'p')
				g_vector = ft_vector(g_vector, "0x", 5, 0);
		}
		else if (g_f->f == 'X')
		{
			if (arg)
				g_vector = ft_vector(g_vector, "0X", 5, 0);
		}
		else if (g_f->f == 'o' && (g_f->dot || (g_f->dot = 2)))
			g_f->pre = g_f->pre > len || arg == 0 ? g_f->pre : len + 1;
	}
	return (1);
}
