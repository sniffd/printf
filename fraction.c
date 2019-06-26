#include "ft_printf.h"
#include <stdio.h>

t_bigint	check_overflow(t_bigint b, int i, int d)
{
	static int	j;

	while (i <= b.start)
	{
		if (b.num[i] < LIM && i >= b.start)
			break;
		b.num[i + 1] = ((b.num[i + 1] - ZERO) * 10) + ((b.num[i] - ZERO) / DIV) + ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
//		while (ft_numlen(b.num[i]) + j < 18)
//		{
//			j++;
//			b = check_overflow(b, i + 1, d + 1);
//			b.num[i + 1] *= 10;
//		}
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	if (d == 0)
		j = 0;
	return (b);
}

t_bigint	check_overflow_five(t_bigint b, int i, int d)
{
	static int	j;

	while (i <= b.start)
	{
		if (b.num[i] < LIM)
			break;
		b.num[i + 1] = (b.num[i + 1] - ZERO) + ((b.num[i] - ZERO) / DIV) + ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
//		while (ft_numlen(b.num[i]) + j < len)
//		{
//			j++;
//			b = check_overflow_five(b, i + 1, d + 1, ft_numlen(b.num[i + 1]));
//			b.num[i + 1] *= 10;
//		}
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	if (d == 0)
		j = 0;
	return (b);
}

static t_bigint	bigint_add_f(t_bigint a, t_bigint b)
{
	t_bigint	res;
	char		biggest;
	int			biggestlen;
	int			lowestlen;
	int			i;
	int			f;
	size_t		mod;
	size_t		div;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	lowestlen = (biggest == 'a' ? b.start + 1 : a.start + 1);
	res.num = ft_memalloc(sizeof(size_t) * (biggestlen + 1));
	res.len = biggestlen + 1;
	i = 0;
	res.start = 0;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	i = 0;
	while (i < biggestlen)
	{
		f = 0;
		if (i < lowestlen)
			res.num[i] = (res.num[i] - ZERO) + (a.num[i] - ZERO) + (b.num[i] - ZERO) + ZERO;
		else
		{
			if (biggest == 'a')
				res.num[i] = (res.num[i] - ZERO) + (a.num[i] - ZERO) + ZERO;
			else
				res.num[i] = (res.num[i] - ZERO) + (b.num[i] - ZERO) + ZERO;
		}
		if (res.num[i] > LIM)
		{
			div = (res.num[i] - ZERO) / DIV;
			mod = (res.num[i] - ZERO) % DIV;
			if (i + 1 == a.start)
			{
				res.num[i + 1] = (res.num[i + 1] - ZERO) + (a.num[i + 1] - ZERO) + ZERO;
				res.num[i] = mod + ZERO;
				res.num[i + 1] = (res.num[i + 1] - ZERO) + (b.num[i + 1] - ZERO) + ZERO;
				res.num[i + 1] = (res.num[i + 1] - ZERO) + div + ZERO;
				i++;
				f = 1;
			}
			else
			{
				res.num[i + 1] = (res.num[i + 1] - ZERO) + div + ZERO;
				res.num[i] = mod + ZERO;
			}
			if (!f && i + 1 == biggestlen)
				res.start = i + 1;
			else
				res.start = i;
		}
		else if (i > res.start)
			res.start++;
		i++;
	}
//		free(a.num);
		printf("\n%s:   ", "a");
//		ft_putchar('\n');
	for (int j = a.start; j >= 0; j--)
	{
		int h;
		if (((h = ft_numlen(a.num[j])) < 18) && j != a.start)
		{
			h = 18 - h;
			while (h--)
				printf("0");
//					ft_putchar('0');
		}
		printf("%zu", a.num[j]);
//			ft_putnbr(res.num[j]);
	}
	printf("\n%s:   ", "b");
//		ft_putchar('\n');
	for (int j = b.start; j >= 0; j--)
	{
		int h;
		if (((h = ft_numlen(b.num[j])) < 18) && j != b.start)
		{
			h = 18 - h;
			while (h--)
				printf("0");
//					ft_putchar('0');
		}
		printf("%zu", b.num[j]);
//			ft_putnbr(res.num[j]);
	}
	printf("\n%s: ", "res");
//		ft_putchar('\n');
	for (int j = res.start; j >= 0; j--)
	{
		int h;
		if (((h = ft_numlen(res.num[j])) < 18) && j != res.start)
		{
			h = 18 - h;
			while (h--)
				printf("0");
//					ft_putchar('0');
		}
		printf("%zu", res.num[j]);
//			ft_putnbr(res.num[j]);
	}
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
		res = check_overflow_five(res, i, 0);
		i--;
	}
	free(b.num);
	return (res);
}

static t_bigint	pow_of_five(int pow)
{
	t_bigint	b;
	int			i;
	int			p;

	p = 0;
	b.len = ft_abs(pow) / 18 + 2;
	b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len);
	b.num[0] = 1 + ZERO;
	b.start = 0;
	while (p < pow)
	{
		i = b.start;
		while (i >= 0)
		{
			b.num[i] = (b.num[i] - ZERO) * 5 + ZERO;
			if (b.num[i] > LIM)
			{
				b.num[i + 1] = (b.num[i + 1] - ZERO) + ((b.num[i] - ZERO) / DIV) + ZERO;
				b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
				if (i + 1 > b.start)
					b.start++;
			}
			i--;
		}
////		printf("\n%i: ", p);
//		ft_putchar('\n');
//		for (int j = b.start; j >= 0; j--)
//		{
//			int h;
//			if (((h = ft_numlen(b.num[j])) < 18) && j != b.start)
//			{
//				h = 18 - h;
//				while (h--)
////					printf("0");
//					ft_putchar('0');
//			}
////			printf("%zu", b.num[j]);
//			ft_putnbr(b.num[j]);
//		}
		p++;
	}
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
	res = check_overflow(res, 0, 0);
	return (res);
}

t_bigint	get_fraction(size_t man, int pow)
{
	t_bigint	res;
	t_bigint	five;
	int			i;
	size_t		bit;
	size_t		mant;

	pow = -pow;
	res.num = (size_t *)ft_memalloc(sizeof(size_t) * (pow / 18 + 1));
	res.num[0] = 1 + ZERO;
//	res.len = 0;
	res.len = pow / 18 + 1;
	res.start = 0;
	i = 1;
	mant = man;
	while (i < pow)
	{
		res = bigint_multy_ten(res);
		i++;
	}
	five = pow_of_five(pow);
	while (mant)
	{
		res = bigint_multy_ten(res);
		bit = (mant & 0x8000000000000000);
		if (bit)
			res = bigint_add_f(res, five);
		mant <<= 1;
		five = bigint_multy_five(five);
		pow++;
	}
	ft_putchar('\n');
		for (int j = res.start; j >= 0; j--)
		{
			int h;
			if (((h = ft_numlen(res.num[j])) < 18) && j != res.start)
			{
				h = 18 - h;
				while (h--)
//					printf("0");
					ft_putchar('0');
			}
//			printf("%zu", res.num[j]);
			ft_putnbr(res.num[j]);
		}
	return (res);
}

//TODO ЕБУЧИЙ НОЛЬ АААААААААААА СУКА ААААА!
//1654299999936483800411224365234375
//1654299999937065876613246917724609375
//16542999999946914613246917724609375
//165429999999469146013246917724609375
//res: 165429973602294921875
//a:   16542997360229492187500
//2490116119384765625
//b:   2384185791015625
//res: 16542999744415283203125
//165429999865591526031494140625
//2328360004365386962890625
//23283064365386962890625
//654299999999999999655830862366201472468674182891845703125
//654314703526660657788320658963674182891845703125
//10000000001654299991934268951416015625
//100000000000165429919999999210558598861109828948974609375