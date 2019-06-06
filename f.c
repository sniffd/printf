#include "ft_printf.h"

void	f_long_double(long double ld)
{
	t_double	d;
	t_bigint	whole;
	t_bigint	fraction;
	size_t		man_w;
	size_t		man_f;

	d.d = ld;
	if (d.s.e - 16383 >= 63)
		whole = get_whole(d.s.m, d.s.e - 16383);
	else if (d.s.e - 16383 < 0)
		fraction = get_fraction(d.s.m, d.s.e - 16383);
	else
	{
		man_w = d.s.m >> (64 - (d.s.e - 16383 + 1));
		man_f = d.s.m << (64 - (64 - (d.s.e - 16383 + 1)));
		whole = get_whole(man_w, (d.s.e - 16383 + 64 - (d.s.e - 16383 + 1)));
		fraction = get_fraction(man_f, d.s.e - 16383 - (d.s.e - 16383 + 1));
	}
}