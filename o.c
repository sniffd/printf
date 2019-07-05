#include "ft_printf.h"

void octal(va_list ap)
{
	if (g_f->hh)
		o_char(ap);
	else if (g_f->h)
		o_short(ap);
	else if (g_f->ll)
		o_long_long(ap);
	else if (g_f->l)
		o_long(ap);
	else
		o_int(ap);
}
