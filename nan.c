#include "ft_printf.h"

int	normal_check(struct s_double d)
{
	if (d.e == 0)
	{
		if (d.m & (1UL << 63))
			return (DENORM);
		else if (d.m & (~(1UL << 63)))
			return (DENORM);
		else
			return (NORM);
	}
	else if (d.e == 32767)
	{
		if (!(d.m & (3UL << 62)))
		{
			if (!(d.m & ((~0UL) >> 2)))
				return (INF);
			else
				return (NAN);
		}
		else if (((d.m & (3UL << 62)) >> 62) == 1)
			return (NAN);
		else if (((d.m & (3UL << 62)) >> 62) == 2)
		{
			if (!(d.m & (~(3UL << 62))))
				return (INF);
			else
				return (NAN);
		}
		else
			return (NAN);
	}
	else
		return (NORM);
}

void	print_nan(int nan, char sign)
{
	char	*s;

	if (nan == NAN)
	{
		s = "nan";
		sign = 0;
	}
	else
		s = "inf";
	if (g_f->wid)
	{
		if (g_f->min)
		{
			f_print_sign(sign, g_f->plu, g_f->spc);
			g_vector = ft_vector(g_vector, s, 5, 0);
			addcharn(' ', (g_f->wid - (3 + (sign || g_f->plu || g_f->spc))));
		}
		else
		{
			addcharn(' ', (g_f->wid - (3 + (sign || g_f->plu || g_f->spc))));
			f_print_sign(sign, g_f->plu, g_f->spc);
			g_vector = ft_vector(g_vector, s, 5, 0);
		}
	}
	else
	{
		f_print_sign(sign, g_f->plu, g_f->spc);
		g_vector = ft_vector(g_vector, s, 5, 0);
	}
}