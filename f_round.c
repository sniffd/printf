#include "ft_printf.h"
#include <stdio.h>

size_t	get_mask(int i)
{
	size_t	mask[19];

	mask[1] = 10;
	mask[2] = 100;
	mask[3] = 1000;
	mask[4] = 10000;
	mask[5] = 100000;
	mask[6] = 1000000;
	mask[7] = 10000000;
	mask[8] = 100000000;
	mask[9] = 1000000000;
	mask[10] = 10000000000;
	mask[11] = 100000000000;
	mask[12] = 1000000000000;
	mask[13] = 10000000000000;
	mask[14] = 100000000000000;
	mask[15] = 1000000000000000;
	mask[16] = 10000000000000000;
	mask[17] = 100000000000000000;
	mask[18] = 1000000000000000000;
	return (mask[i]);
}

void	math_round(t_bigint *b, t_round *r, char flag)
{
	if (r->next_digit > 4)
	{
		b->num[r->index] = !flag ? b->num[r->index] + 1 : b->num[r->index] + r->mask;
		*b = check_overflow_five(*b, r->index);
	}
}

void	printf_round(t_bigint *b, int index, size_t mask, char flag)
{
	size_t	number;

	if (!flag)
		number = b->num[0];
	else
		number = b->num[index] / mask % 10;
	if (number % 2 == 1)
	{
		b->num[index] = !flag ? b->num[index] + 1 : b->num[index] + mask;
		*b = check_overflow_five(*b, index);
	}
}

void	check_zero(t_bigint *f, t_round *r, int len, char flag)
{
	int	i;

	i = r->index;
	if (r->nmb_pos != len && f->num[r->index] % (r->mask / 10))
		math_round(f, r, flag);
	else
	{
		while (i > 0)
		{
			if ((f->num[--i] - ZERO))
			{
				math_round(f, r, flag);
				return ;
			}
		}
		printf_round(f, r->index, r->mask, flag);
	}
}

void	fraction_select_round(t_bigint *f, t_round *r, char flag)
{
	int	len;

	len = ft_numlen(f->num[r->index]) - 1;
	r->mask = get_mask(len - r->nmb_pos);
	r->next_digit = (r->nmb_pos == len) ?
			f->num[r->index - 1] / 100000000000000000 % 10 :
			f->num[r->index] % r->mask / (r->mask / 10);
	if (r->next_digit != 5)
		math_round(f, r, flag);
	else
		check_zero(f, r, len, flag);
}

void	whole_select_round(t_bigint *f, t_bigint *w, t_round *r, char flag)
{
	int f_digit;

	r->mask = get_mask(ft_numlen(f->num[f->start]) - 1);
	f_digit = f->num[f->start] % r->mask / (r->mask / 10);
	r->next_digit = f_digit;
	if (f_digit != 5)
		math_round(w, r, flag);
	else
		check_zero(w, r, -255, flag);
}

void	fraction_round(t_bigint *f, t_round *r)
{
	int pre;
	int start_len;

	start_len = ft_numlen(f->num[f->start]) - 1;
	if (g_f->pre < f->start * CLUSTER_SIZE + start_len)
	{
		pre = ((g_f->pre - start_len > 0) ? g_f->pre - start_len : 0);
		r->index = f->start -
				(pre / CLUSTER_SIZE + ((pre % CLUSTER_SIZE != 0) * 1));
		if (r->index == f->start)
			r->nmb_pos = g_f->pre % (start_len + 1);
		else if (g_f->pre < CLUSTER_SIZE)
			r->nmb_pos = (g_f->pre - start_len) % CLUSTER_SIZE;
		else
		{
			r->nmb_pos = (g_f->pre - start_len) % CLUSTER_SIZE;
			if (r->nmb_pos == 0)
				r->nmb_pos = 18;
		}
		fraction_select_round(f, r, 1);
	}
}

void	f_round(t_bigint w, t_bigint f)
{
	t_round	r;

	r.index = 0;
	if (g_f->pre > 0)
		fraction_round(&f, &r);
	else
	{
		r.index = 0;
		r.nmb_pos = ft_numlen(f.num[0]) - 1;
		whole_select_round(&f, &w, &r, 0);
	}
	print(f, w, r.index, r.nmb_pos);
}