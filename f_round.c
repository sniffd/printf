#include "ft_printf.h"
#include <stdio.h>

void	math_round(t_bigint f, t_bigint w, int index, int digit, size_t mask,
				   int next_number, char fl)
{
	if (next_number > 4)
	{
		f.num[index] = !fl ? f.num[index] + 1 : f.num[index] + mask;
		f = check_overflow_five(f, index, 255);
	}
	ft_putchar('\n');
	for (int j = f.start; j >= 0; j--)
	{
		ft_putnbr(f.num[j]);
		ft_putchar('_');
	}
	printf("hueta\n");
}

void	printf_round(t_bigint f, t_bigint w, int index, int digit, size_t mask,
					 char fl)
{
	size_t	number;

	if (!fl)
		number = f.num[0];
	else
		number = f.num[index] / mask % 10;
	if (number % 2 == 1)
	{
		f.num[index] = !fl ? f.num[index] + 1 : f.num[index] + mask;
		f = check_overflow_five(f, index, 255);
	}
	ft_putchar('\n');
	for (int j = f.start; j >= 0; j--)
	{
		ft_putnbr(f.num[j]);
		ft_putchar('_');
	}
	printf("zaebumba\n");
}

void	check_zero(t_bigint f, t_bigint w, int index, int digit, int len, size_t mask,
				   int next_number, char fl)
{
	int	i;
//	size_t	mask;
	int	flg;

	i = index;
	flg = 0;
//	mask = 1;
	if (digit == len)
	{
		while (i >= 0 && !(f.num[--i] - ZERO))
			;
		if (i >= 0)
			math_round(f, w, index, digit, mask, next_number, fl);
		else
			printf_round(f, w, index, digit, mask, fl);
	}
	else
	{
//		while (flg != len - digit - 1)
//		{
//			mask *= 10;
//			flg++;
//		}
		if (f.num[index] % (mask / 10))
			math_round(f, w, index, digit, mask, next_number, fl);
		else
		{
			while (i >= 0 && !(f.num[--i] - ZERO))
				;
			if (i >= 0)
				math_round(f, w, index, digit, mask, next_number, fl);
			else
				printf_round(f, w, index, digit, mask, fl);
		}
	}
//		if (f.start != index && index > 0 && f.num[index - 1] - ZERO != 0)
//			math_round();
}

void	select_round(t_bigint f, t_bigint w, int index, int digit, char fl)
{
	int next_number;
	size_t	mask;
	int flg;
	int	len;

	mask = 1;
	flg = 0;
	len = ft_numlen(f.num[index]) - 1;
	if (fl)
	{
		if (digit == len)
			next_number = f.num[index - 1] / 100000000000000000 % 10;
		else
		{
			while (flg != len - digit)
			{
				mask *= 10;
				flg++;
			}
			next_number = f.num[index] % mask / (mask / 10);
		}
		if (next_number != 5)
			math_round(f, w, index, digit, mask, next_number, fl);
		else
			check_zero(f, w, index, digit, len, mask, next_number, fl);
	}
	else
	{
		while (flg != (ft_numlen(f.num[f.start]) - 1))
		{
			mask *= 10;
			flg++;
		}
		next_number = f.num[f.start] % mask / (mask / 10);
		if (next_number != 5)
			math_round(w, w, index, digit, mask, next_number, fl);
		else
			check_zero(w, w, index, digit, -255, mask, next_number, fl);
	}
	printf("\n%i\n", next_number);
}

void	fraction_round(t_bigint f)
{
	int	index;
	int digit;
	int pre;
	int start_len;


	start_len = ft_numlen(f.num[f.start]) - 1;
	if (g_f->pre < f.start * CLUSTER_SIZE + start_len)
	{
		pre = ((g_f->pre - start_len > 0) ? g_f->pre - start_len : 0);
		index = f.start -
				(pre / CLUSTER_SIZE + ((pre % CLUSTER_SIZE != 0) * 1));
//	pre = ft_numlen(f.num[index]) - 1;
		if (index == f.start)
			digit = g_f->pre % (start_len + 1);
		else if (g_f->pre < CLUSTER_SIZE)
			digit = (g_f->pre - start_len) % CLUSTER_SIZE;
		else
		{
			digit = (g_f->pre - start_len) % CLUSTER_SIZE;
			if (digit == 0)
				digit = 18;
		}
		select_round(f, f, index, digit, 1);
	printf("\nindex %i\n", index);
	printf("digit %i\n", digit);
	}
}

void	whole_round(t_bigint w, t_bigint f)
{
	int digit;

	digit = ft_numlen(f.num[0]) - 1;
	select_round(f, w, 0, digit, 0);
	printf("digit %i\n", digit);
}

void	f_round(t_bigint w, t_bigint f)
{
	if (g_f->pre > 0)
		fraction_round(f);
	else
		whole_round(w, f);
}