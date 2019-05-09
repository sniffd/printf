#include "ft_printf.h"

void	character(va_list ap)
{
	char	c;

	c = va_arg(ap, char);
	if (f->wid)
	{
		if (f->min)
		{
			vector = ft_vector(vector, &c, 5, 1);
			addcharn(' ', (f->wid - 1));
		}
		else
		{
			addcharn(' ', (f->wid - 1));
			vector = ft_vector(vector, &c, 5, 1);
		}
	}
	else
		vector = ft_vector(vector, &c, 5, 1);
}
