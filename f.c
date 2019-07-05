#include "ft_printf.h"

void	f_round(t_bigint w, t_bigint f);

void	f_double(va_list ap)
{
	t_double	d;
	t_bigint	whole;
	t_bigint	fraction;
	size_t		man_w;
	size_t		man_f;
	long double	ld;

	ld = va_arg(ap, long double);
	d.d = ld;
	whole.num = NULL;
	fraction.num = NULL;
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
	f_round(whole, fraction);
}

void	f_f(va_list ap)
{
	if (g_f->bl)
		f_long_double(ap);
//	else
//		f_double();

}

void	f_long_double(va_list ap)
{
	t_double	d;
	t_bigint	whole;
	t_bigint	fraction;
	size_t		man_w;
	size_t		man_f;
	long double	ld;

	ld = va_arg(ap, long double);
	d.d = ld;
	whole.num = NULL;
	fraction.num = NULL;
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
	f_round(whole, fraction);
}