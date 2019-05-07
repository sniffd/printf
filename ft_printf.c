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
			else if (f->f == 'o')
				octal(f, ap);
			else if (f->f == 's')
				string(f, ap);
			else if (f->f == 'c')
				character(f, ap);
			else if (f->f == 'X')
				hex(f, ap);
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