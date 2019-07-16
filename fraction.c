#include "ft_printf.h"
#include <stdio.h>

t_bigint check_overflow(t_bigint b, int i)
{
	while (i <= b.start)
	{
		if (b.num[i] < LIM && i >= b.start)
			break;
		b.num[i + 1] = ((b.num[i + 1] - ZERO) * 10) + ((b.num[i] - ZERO) / DIV)
				+ ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

t_bigint check_overflow_five(t_bigint b, int i)
{
	while (i <= b.start)
	{
		if (b.num[i] < LIM)
			break;
		b.num[i + 1] = (b.num[i + 1] - ZERO) + ((b.num[i] - ZERO) / DIV) + ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

int		if_or_else(t_bigint *res, t_bigint a, t_bigint b, int *i)
{
	size_t		mod;
	size_t		div;

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

int		kek(t_bigint *res, int i, t_bigint a, t_bigint b)
{
	char		biggest;
	int			biggestlen;

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

void	while_i_less_biggistlen(t_bigint *res, t_bigint a, t_bigint b, int i)
{
	char		biggest;
	int			biggestlen;
	int			lowestlen;

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
		if (i > res->start && !kek(res, i, a, b))
			res->start++;
		i++;
	}
}

static t_bigint	bigint_add_f(t_bigint a, t_bigint b)
{
	t_bigint	res;
	char		biggest;
	int			biggestlen;
	int			i;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	res.num = ft_memalloc(sizeof(size_t) * (biggestlen + 1));
	res.len = biggestlen + 1;
	i = 0;
	res.start = 0;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	while_i_less_biggistlen(&res, a, b, 0);

//	free(b.num);
	free(a.num);
	return (res);
}

static t_bigint	bigint_multy_five(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.len = b.start + 2;
	res.num = (size_t *)ft_memalloc(sizeof(size_t) * res.len);
	res.start = b.start;
	i = b.start + 1;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	i = b.start;
	while (i >= 0)
	{
		res.num[i] = (b.num[i] - ZERO) * 5 + ZERO;
		res = check_overflow_five(res, i);
		i--;
	}
	free(b.num);
	return (res);
}

static void	power_of_five(int pow, int p, int i, t_bigint *b)
{
	while (p < pow)
	{
		i = b->start;
		while (i >= 0)
		{
			b->num[i] = (b->num[i] - ZERO) * 5 + ZERO;
			if (b->num[i] > LIM)
			{
				b->num[i + 1] = (b->num[i + 1] - ZERO) + ((b->num[i] - ZERO)
						/ DIV) + ZERO;
				b->num[i] = ((b->num[i] - ZERO) % DIV) + ZERO;
				if (i + 1 > b->start)
					b->start++;
			}
			i--;
		}
		p++;
	}
}

static t_bigint	pow_of_five(int pow)
{
	t_bigint	b;
	int			i;
	int			p;

	p = 0;
	b.len = (ft_abs(pow) / 18) + 2;
	b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len);
	b.num[0] = 1 + ZERO;
	b.start = 0;
	i = 1;
	while (i < b.len)
	{
		b.num[i] = ZERO;
		i++;
	}
	power_of_five(pow, p, i, &b);
	return (b);
}

static t_bigint	bigint_multy_ten(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.start = b.start;
	res.len = b.len + 1;
	res.num = ft_memalloc(sizeof(size_t) * res.len);
	i = b.start;
	while (i > 0)
	{
		res.num[i] = b.num[i];
		i--;
	}
	i = b.start + 1;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	res.num[0] = ((b.num[0] - ZERO) * 10) + ZERO;
	res = check_overflow(res, 0);
	return (res);
}

t_bigint	get_null(void)
{
	t_bigint	res;

	res.num = ft_memalloc(8);
	res.num[0] = 0;
	res.start = 0;
	res.len = 1;
	res.sign = 0;
	return (res);
}

void 		experiment(size_t mant, t_bigint *res, int pow)
{
	t_bigint	five;
	size_t		bit;
	int			f;

	f = 0;
	five = pow_of_five(pow);
	while (mant)
	{
		*res = bigint_multy_ten(*res);
		bit = (mant & 0x8000000000000000);
		if (bit)
		{
			*res = bigint_add_f(*res, five);
			f = 1;
		}
		mant <<= 1;
		five = bigint_multy_five(five);
		pow++;
	}
	if (!f)
		res->num[0] = ZERO;
	res->num[res->start] -= ZERO;
	free(five.num);
}

t_bigint	get_fraction(size_t man, int pow)
{
	t_bigint	res;
	int			i;
	size_t		mant;

	pow = -pow;
	res.num = (size_t *)ft_memalloc(sizeof(size_t) * (pow / 18 + 1));
	res.num[0] = 1 + ZERO;
	res.len = pow / 18 + 1;
	res.start = 0;
	i = 1;
	mant = man;
	while (i < pow)
	{
		res = bigint_multy_ten(res);
		i++;
	}
	experiment(mant, &res, pow);
	return (res);
}
