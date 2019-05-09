#include "ft_printf.h"

void octal(va_list ap)
{
	if (f->hh)
		o_char(ap);
	else if (f->h)
		o_short(ap);
	else if (f->ll)
		o_long_long(ap);
	else if (f->l)
		o_long(ap);
	else
		o_int(ap);
}
