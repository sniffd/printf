#include "ft_printf.h"

int	string(va_list ap, t_f *f)
{
	size_t	len;
	char	*s;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (f->wid)
	{
		if (f->min)
		{
			ft_putstr(s);
			ft_putcharn(' ', (f->wid - len));
		}
		else
		{
			ft_putcharn(' ', (f->wid - len));
			ft_putstr(s);
		}
	}
	else
		ft_putstr(s);
	return (0);
}