#include "ft_printf.h"

int	character(va_list ap, t_f *f)
{
	char	c;

	c = va_arg(ap, char);
	if (f->wid)
	{
		if (f->min)
		{
			ft_putchar(c);
			ft_putcharn(' ', (f->wid - 1));
		}
		else
		{
			ft_putcharn(' ', (f->wid - 1));
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	return (0);
}