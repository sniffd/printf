#include "ft_printf.h"
#include <stdio.h>

static t_bigint	pow_of_two(int pow)
{
	t_bigint	b;
	int			i;
	int			p;

	p = 0;
	b.len = pow / 59 + 1;
	b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len);
	b.num[0] = 1;
	b.start = 0;
	while (p < pow)
	{
		i = b.start;
		while (i >= 0)
		{
			b.num[i] <<= 1;
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

static t_bigint	bigint_add(t_bigint a, t_bigint b)
{
	t_bigint	res;
	char		biggest;
	int			biggestlen;
	int			lowestlen;
	int			i;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	lowestlen = (biggest == 'a' ? b.start + 1 : a.start + 1);
	res.num = ft_memalloc(sizeof(size_t) * (biggestlen + 1));
	res.len = biggestlen;
	i = 0;
	res.start = 0;
	while (i < biggestlen)
	{
		if (i < lowestlen)
			res.num[i] = res.num[i] + a.num[i] + b.num[i];
		else
			res.num[i] = (biggest == 'a' ? res.num[i] + a.num[i] : res.num[i] + b.num[i]);
		if (res.num[i] > LIM)
		{
			res.num[i + 1] = res.num[i + 1] + (res.num[i] / DIV);
			res.num[i] = res.num[i] % DIV;
			if (i + 1 > res.start)
				res.start++;
			if (i + 1 == biggestlen)
				biggestlen++;
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
//	free(a.num);
//	free(b.num);
	return (res);
}

static t_bigint	bigint_multy_two(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.len = b.start + 2;
	res.num = (size_t *)ft_memalloc(sizeof(size_t) * res.len);
	res.start = b.start;
	i = b.start;
	while (i >= 0)
	{
		res.num[i] = (b.num[i]) << 1;
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

t_bigint	get_whole(size_t man, int pow)
{
	t_bigint	res;
	t_bigint	two;
	size_t	mant;
	char	bit;

	res.num = (size_t *)ft_memalloc(8);
	res.len = 0;
	res.start = 0;
	mant = man;
	pow = pow - 63;
	two = pow_of_two(pow);
	while (mant)
	{
		bit = mant & 1;
		if (bit)
			res = bigint_add(res, two);
		mant >>= 1;
		pow++;
		two = bigint_multy_two(two);
	}
	//		printf("\n%i: ", p);
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
