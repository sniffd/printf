#include "ft_printf.h"
#include <stdio.h>

static t_bigint	bigint_add_f(t_bigint a, t_bigint b)//TODO отдебажить 16 итерацию
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
	res.len = biggestlen;
	i = 0;
	f = 0;
	res.start = 0;
	while (i < biggestlen)
	{
		if (i < lowestlen)
			res.num[i] = res.num[i] + a.num[i] + b.num[i];
		else
		{
			if (biggest == 'a')
				res.num[i] = res.num[i] + a.num[i];
			else
				res.num[i] = res.num[i] + b.num[i];
		}
		if (res.num[i] > LIM)
		{
			div = res.num[i] / DIV;
			mod = res.num[i] % DIV;
			if (mod < 100000000000000000 && (i < a.start || i < b.start))
				f = 1;
			if (i + 1 == a.start)
			{
				res.num[i + 1] = (res.num[i + 1] + a.num[i + 1]);
				res.num[i] = mod;
				res.num[i + 1] += b.num[i + 1];
				res.num[i + 1] = res.num[i + 1] + div;
				i++;
			}
			else
			{
				res.num[i + 1] = res.num[i + 1] + div;
				res.num[i] = mod;
			}
			if (i + 1 > res.start)
				res.start = i + 1;
			if (res.start == biggestlen)
				res.start--;
		}
		else if (i > res.start)
			res.start++;
		i++;
	}
//	printf("\n%s:   ", "a");
////		ft_putchar('\n');
//	for (int j = a.start; j >= 0; j--)
//	{
//		int h;
//		if (((h = ft_numlen(a.num[j])) < 18) && j != a.start)
//		{
//			h = 18 - h;
//			while (h--)
//				printf("0");
////					ft_putchar('0');
//		}
//		printf("%zu", a.num[j]);
////			ft_putnbr(res.num[j]);
//	}
//	printf("\n%s:   ", "b");
////		ft_putchar('\n');
//	for (int j = b.start; j >= 0; j--)
//	{
//		int h;
//		if (((h = ft_numlen(b.num[j])) < 18) && j != b.start)
//		{
//			h = 18 - h;
//			while (h--)
//				printf("0");
////					ft_putchar('0');
//		}
//		printf("%zu", b.num[j]);
////			ft_putnbr(res.num[j]);
//	}
//	printf("\n%s: ", "res");
////		ft_putchar('\n');
//	for (int j = res.start; j >= 0; j--)
//	{
//		int h;
//		if (((h = ft_numlen(res.num[j])) < 18) && j != res.start)
//		{
//			h = 18 - h;
//			while (h--)
//				printf("0");
////					ft_putchar('0');
//		}
//		printf("%zu", res.num[j]);
////			ft_putnbr(res.num[j]);
//	}
////	free(a.num);
////	free(b.num);
	return (res);
}

static t_bigint	bigint_multy_five(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.len = b.start + 2;
	res.num = (size_t *)ft_memalloc(sizeof(size_t) * res.len);
	res.start = b.start;
	i = b.start;
	while (i >= 0)
	{
		res.num[i] = b.num[i] * 5;
		if (res.num[i] > LIM)
		{
			res.num[i + 1] = res.num[i + 1] + (res.num[i] / DIV);
			res.num[i] = res.num[i] % DIV;
			if (i + 1 > res.start)
				res.start++;
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
	b.num[0] = 1;
	b.start = 0;
	while (p < pow)
	{
		i = b.start;
		while (i >= 0)
		{
			b.num[i] *= 5;
			if (b.num[i] > LIM)
			{
				b.num[i + 1] = b.num[i + 1] + (b.num[i] / DIV);
				b.num[i] = b.num[i] % DIV;
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
	int	i;

	i = 0;
	b.num[0] *= 10;
	while (b.num[i] > LIM || i < b.start)
	{
		b.num[i + 1] = (b.num[i + 1] * 10) + (b.num[i] / DIV);
		b.num[i] = b.num[i] % DIV;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

t_bigint	get_fraction(size_t man, int pow)
{
	t_bigint	res;
	t_bigint	five;
	int			i;
	size_t		bit;
	size_t		mant;

	pow = -pow;
	res.num = (size_t *)ft_memalloc(sizeof(size_t) * pow / 18 + 1);
	res.num[0] = 1;
	res.len = 0;
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
