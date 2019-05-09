#include "ft_printf.h"

void	string(va_list ap)
{
	size_t	len;
	char	*s;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (f->wid)
	{
		if (f->min)
		{
			vector = ft_vector(vector, s, 5, 0);
			addcharn(' ', (f->wid - len));
		}
		else
		{
			addcharn(' ', (f->wid - len));
			vector = ft_vector(vector, s, 5, 0);
		}
	}
	else
		vector = ft_vector(vector, s, 5, 0);
}
