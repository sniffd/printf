#include "ft_printf.h"

void	string(va_list ap)
{
	size_t	len;
	char	*s;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (g_f->wid)
	{
		if (g_f->min)
		{
			g_vector = ft_vector(g_vector, s, 5, 0);
			addcharn(' ', (g_f->wid - len));
		}
		else
		{
			if (g_f->zer)
				addcharn('0', (g_f->wid - len));
			else
				addcharn(' ', (g_f->wid - len));
			g_vector = ft_vector(g_vector, s, 5, 0);
		}
	}
	else
		g_vector = ft_vector(g_vector, s, 5, 0);
}
