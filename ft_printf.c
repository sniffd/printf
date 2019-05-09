#include "ft_printf.h"

char	*vector = NULL;
t_f		*f = NULL;

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			f = parse(&format, ap);
			if (f->f == 'i' || f->f == 'd')
				integer(ap);
			else if (f->f == 'o')
				octal(ap);
			else if (f->f == 's')
				string(ap);
			else if (f->f == 'c')
				character(ap);
			else if (f->f == 'X')
				big_hex(ap);
			else if (f->f == 'x')
				hex(ap);
		}
		else
		{
			vector = ft_vector(vector, format, 5, 1);
			format++;
		}
	}
	va_end(ap);
	len = ft_strlen(vector);
	write(1, vector, len);
	ft_strdel(&vector);
	return (len);
}
//%[флаги][ширина][.точность][размер]тип