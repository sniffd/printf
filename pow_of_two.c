#include "ft_printf.h"
#include <stdio.h>

t_bigint	pow_of_two(size_t man, int pow)//TODO запилить zero case
{
	t_bigint	b;
	int			i;
	int			end;
	int			p;

	p = 0;
	b.len = pow / 59 + 1;
	end = b.len - 1;
	b.start = end;
	b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len);
	b.num[end] = 1;
	while (p < pow)
	{
		i = b.start;
		while (i <= end)
		{
			b.num[i] <<= 1;
			if (b.num[i] > LIM)
			{
				b.num[i - 1] = b.num[i - 1] + (b.num[i] / DIV);
				b.num[i] = b.num[i] % DIV;
				if (i - 1 < b.start)
					b.start--;
			}
			i++;
		}
//		printf("\n%i: ", p);
//		for (int j = b.start; j <= end; j++)
//		{
//			int h;
//			if (((h = ft_numlen(b.num[j])) < 18) && j != b.start)
//			{
//				h = 18 - h;
//				while (h--)
//					printf("0");
//			}
//			printf("%zu", b.num[j]);
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

	}
}
