#include "ft_printf.h"

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
	else
		r->nmb_pos = 18;
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

//void	math_round(t_bigint *b, t_round *r, char flag)
//{
//	if (r->next_digit > 4)
//	{
//		b->num[r->index] = !flag ? b->num[r->index] + 1
//				: b->num[r->index] + r->mask;
//		*b = check_overflow_five(*b, r->index);
//	}
//}
//
//void	printf_round(t_bigint *b, int index, size_t mask, char flag)
//{
//	size_t	number;
//
//	if (!flag)
//		number = b->num[0];
//	else
//		number = b->num[index] / mask % 10;
//	if (number % 2 == 1)
//	{
//		b->num[index] = !flag ? b->num[index] + 1 : b->num[index] + mask;
//		*b = check_overflow_five(*b, index);
//	}
//}
//
//void	check_zero(t_bigint *f, t_round *r, int len, char flag)
//{
//	int	i;
//
//	i = r->index;
//	if (r->nmb_pos != len && f->num[r->index] % (r->mask / 10))
//		math_round(f, r, flag);
//	else
//	{
//		while (i > 0)
//		{
//			if ((f->num[--i] - ZERO))
//			{
//				math_round(f, r, flag);
//				return ;
//			}
//		}
//		printf_round(f, r->index, r->mask, flag);
//	}
//}
//
//void	fraction_round(t_bigint *f, t_round *r)
//{
//	int pre;
//	int start_len;
//
//	start_len = ft_numlen(f->num[f->start]) - 1;
//	if (g_f->pre < f->start * CLUSTER_SIZE + start_len)
//	{
//		pre = ((g_f->pre - start_len > 0) ? g_f->pre - start_len : 0);
//		r->index = f->start -
//				(pre / CLUSTER_SIZE + ((pre % CLUSTER_SIZE != 0) * 1));
//		if (r->index == f->start)
//			r->nmb_pos = g_f->pre % (start_len + 1);
//		else if (g_f->pre < CLUSTER_SIZE)
//			r->nmb_pos = (g_f->pre - start_len) % CLUSTER_SIZE;
//		else
//		{
//			r->nmb_pos = (g_f->pre - start_len) % CLUSTER_SIZE;
//			if (r->nmb_pos == 0)
//				r->nmb_pos = 18;
//		}
//		fraction_select_round(f, r, 1);
//	}
//}
//
//void	f_round(t_bigint w, t_bigint f)
//{
//	t_round	r;
//
//	r.index = 0;
//	if (g_f->pre > 0)
//		fraction_round(&f, &r);
//	else
//	{
//		r.index = 0;
//		r.nmb_pos = ft_numlen(f.num[0]) - 1;
//		whole_select_round(&f, &w, &r, 0);
//	}
//	print(f, w, r.index, r.nmb_pos);
//}
