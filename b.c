#include "ft_printf.h"

void	binary(va_list ap)
{
	if (g_f->hh)
		b_char(ap);
	else if (g_f->h)
		b_short(ap);
	else if (g_f->ll)
		b_long_long(ap);
	else if (g_f->l || g_f->f == 'p')
		b_long(ap);
	else
		b_int(ap);
}
