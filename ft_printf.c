#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_f		*f;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			f = parse(&format, ap);
			if (f->f == 'i' || f->f == 'd')
				integer(f, ap);
			else if (f->f == 's')
				string(ap, f);
			else if (f->f == 'c')
				character(ap, f);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (0);
}
//%[флаги][ширина][.точность][размер]тип