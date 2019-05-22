#include "ft_printf.h"
#include <stdio.h>

t_bigint	pow_of_two(size_t man, int pow)//TODO запилить zero case
{
	t_bigint	b;
	int			i;
	int			end;
	int			begin;
	int			p;

	p = 0;
	b.len = pow / 59 + 1;
	end = b.len - 1;
	begin = end;
	b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len);
	b.num[end] = 1;
	while (p < pow)
	{
		i = begin;
		while (i <= end)
		{
			b.num[i] <<= 1;
			if (b.num[i] > LIM)
			{
				b.num[i - 1] = b.num[i - 1] + (b.num[i] / DIV);
				b.num[i] = b.num[i] % DIV;
				if (i - 1 < begin)
					begin--;
			}
			i++;
		}
//		printf("\n%i: ", p);
//		for (int j = begin; j <= end; j++)
//		{
//			int h;
//			if (((h = ft_numlen(b.num[j])) < 18) && j != begin)
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
