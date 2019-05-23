#include "ft_printf.h"
#include <stdio.h>

t_bigint	pow_of_two(size_t man, int pow)//TODO запилить zero case
{
	t_bigint	b;
	int			i;
	int			p;

	p = 0;
	b.len = pow / 59 + 1;
	b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len);
	b.num[0] = 1;
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

t_bigint	bigint_add(t_bigint a, t_bigint b)
{
	t_bigint	res;
	char		biggest;
	int			biggestlen;
	int			lowestlen;
	int			i;
	int			end;

	biggest = a.len > b.len ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.len : b.len);
	lowestlen = (biggest == 'a' ? b.len : a.len);
	res.num = ft_memalloc(sizeof(size_t) * (biggestlen + 1));
	res.len = biggestlen + 1;
	i = 0;
	end = res.len - 1;
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
		}
		if (i > res.start)
			res.start++;
		i++;
	}
}

