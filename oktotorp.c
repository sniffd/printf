#include "ft_printf.h"

int	oktotorp(unsigned long long arg, int len)
{
	if (f->okt)
	{
		if (f->f == 'x')
		{
			if (arg)
				vector = ft_vector(vector, "0x", 5, 0);
		}
		else if (f->f == 'X')
		{
			if (arg)
				vector = ft_vector(vector, "0X", 5, 0);
		}
		else if (f->f == 'o' && (f->dot || (f->dot = 2)))
			f->pre = f->pre > len || arg == 0 ? f->pre : len + 1;
	}
	return (1);
}
