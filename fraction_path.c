#include "ft_printf.h"

t_bigint	check_overflow(t_bigint b, int i)
{
	while (i <= b.start)
	{
		if (b.num[i] < LIM && i >= b.start)
			break ;
		b.num[i + 1] = ((b.num[i + 1] - ZERO) * 10) + ((b.num[i] - ZERO) / DIV)
				+ ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

t_bigint	check_overflow_five(t_bigint b, int i)
{
	while (i <= b.start)
	{
		if (b.num[i] < LIM)
			break ;
		b.num[i + 1] = (b.num[i + 1] - ZERO) + ((b.num[i] - ZERO) / DIV) + ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

int			if_or_else(t_bigint *res, t_bigint a, t_bigint b, int *i)
{
	size_t	mod;
	size_t	div;

	div = (res->num[*i] - ZERO) / DIV;
	mod = (res->num[*i] - ZERO) % DIV;
	if (*i + 1 == a.start)
	{
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + (a.num[*i + 1] - ZERO)
				+ ZERO;
		res->num[*i] = mod + ZERO;
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + (b.num[*i + 1] - ZERO)
				+ ZERO;
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + div + ZERO;
		(*i)++;
		return (1);
	}
	else
	{
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + div + ZERO;
		res->num[*i] = mod + ZERO;
		return (0);
	}
}

int			if_i_biggest_lim(t_bigint *res, int i, t_bigint a, t_bigint b)
{
	char	biggest;
	int		biggestlen;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	if (res->num[i] > LIM)
	{
		if (!if_or_else(res, a, b, &i) && i + 1 == biggestlen)
			res->start = i + 1;
		else
			res->start = i;
		return (1);
	}
	else
		return (0);
}

void		while_i_less_biggistlen(t_bigint *res, t_bigint a, t_bigint b,
		int i)
{
	char	biggest;
	int		biggestlen;
	int		lowestlen;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	lowestlen = (biggest == 'a' ? b.start + 1 : a.start + 1);
	while (i < biggestlen)
	{
		if (i < lowestlen)
			res->num[i] = (res->num[i] - ZERO) + (a.num[i] - ZERO) + (b.num[i]
					- ZERO) + ZERO;
		else
		{
			if (biggest == 'a')
				res->num[i] = (res->num[i] - ZERO) + (a.num[i] - ZERO) + ZERO;
			else
				res->num[i] = (res->num[i] - ZERO) + (b.num[i] - ZERO) + ZERO;
		}
		if (i > res->start && !if_i_biggest_lim(res, i, a, b))
			res->start++;
		i++;
	}
}
