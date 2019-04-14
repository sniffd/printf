#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		t;
	int		*f;

	t = 0;
//	f = ft_memalloc(sizeof(int) * )
	va_start(ap, format);
	while (*format)
	{
		if (!t && *format == '%')
		{
			t = 1;
			format++;
		}
		else if (!t)
		{
			ft_putchar(*format);
			format++;
		}
		else if (t && *format == 'i')
		{
			ft_putnbr(va_arg(ap, int));
			t = 0;
			format++;
		}
	}
	va_end(ap);
	return (0);
}
//%[флаги][ширина][.точность][размер]тип