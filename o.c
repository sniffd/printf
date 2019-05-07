#include "ft_printf.h"

int	octal(t_f *f, va_list ap)
{
	if (f->hh)
		o_char(f, ap);
	else if (f->h)
		o_short(f, ap);
	else if (f->ll)
		o_long_long(f, ap);
	else if (f->l)
		o_long(f, ap);
	else
		o_int(f, ap);
	return (0);
}