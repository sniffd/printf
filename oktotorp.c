#include "ft_printf.h"

int	oktotorp(t_f *f, unsigned long long arg, int len)
{
	if (f->okt)
	{
		if (f->f == 'x')
		{
			if (arg)
				ft_putstr("0x");
			else if (!(f->dot && (f->pre)))
				ft_putchar('0');
			return (0);
		}
		if (f->f == 'X')
		{
			if (arg)
				ft_putstr("0X");
			else if (!(f->dot && (f->pre)))
				ft_putchar('0');
			return (0);
		}
		if (f->f == 'o' && (f->dot || (f->dot = 2)))
		{
			f->pre = f->pre > len || arg == 0 ? f->pre : len + 1;
			return (0);
		}
	}
	return (0);
}