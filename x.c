#include "ft_printf.h"

void	big_hex(va_list ap)
{
	if (f->hh)
		big_x_char(ap);
	else if (f->h)
		big_x_short(ap);
	else if (f->ll)
		big_x_long_long(ap);
	else if (f->l)
		big_x_long(ap);
	else
		big_x_int(ap);
}

void	hex(va_list ap)
{
	if (f->hh)
		x_char(ap);
	else if (f->h)
		x_short(ap);
	else if (f->ll)
		x_long_long(ap);
	else if (f->l)
		x_long(ap);
	else
		x_int(ap);
}
