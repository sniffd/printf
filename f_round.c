#include "ft_printf.h"
#include <stdio.h>

void	whole_round(t_bigint w, t_bigint f)
{

}

void	fraction_round(t_bigint f)
{
	int	index;
	int	digit;
	int i;
	int pre;

	i = f.start;
	pre = g_f->pre - ft_numlen(f.num[i]);
//	if (i > 0)
//		index = i - (pre / CLUSTER_SIZE);
//	else
//		index = i;
//	index = f.start - g_f->pre / CLUSTER_SIZE;
	index = f.start - (g_f->pre - ft_numlen(f.num[f.start])) / 19 - 1;
//	digit = g_f->pre % CLUSTER_SIZE + 1;
//	digit = CLUSTER_SIZE + 1 - ((((index - 1) * CLUSTER_SIZE) + ft_numlen(f.num[f.start])) - g_f->pre);
	digit = CLUSTER_SIZE - ((CLUSTER_SIZE * (f.start - index) + ft_numlen(f.num[f.start])) - g_f->pre) + 1;
//	digit = (g_f->pre - ft_numlen(f.num[f.start])) % CLUSTER_SIZE;
	printf("\nindex %i\n", index);
	printf("digit %i\n", digit);
}

void	f_round(t_bigint w, t_bigint f)
{
	if (g_f->pre > 0)
		fraction_round(f);
	else
		whole_round(w, f);
}