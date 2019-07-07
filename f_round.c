#include "ft_printf.h"
#include <stdio.h>

void	whole_round(t_bigint w, t_bigint f)
{

}

void	fraction_round(t_bigint f)
{
	int	index;
	int digit;
	int pre;
	int start_len;

	start_len = ft_numlen(f.num[f.start]) - 1;
	pre = ((g_f->pre - start_len > 0) ? g_f->pre - start_len : 0);
	index = f.start - (pre / CLUSTER_SIZE + ((pre % CLUSTER_SIZE != 0) * 1));
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
//	printf("\nindex %i\n", index);
//	printf("digit %i\n", digit);
}

void	f_round(t_bigint w, t_bigint f)
{
	if (g_f->pre > 0)
		fraction_round(f);
	else
		whole_round(w, f);
}