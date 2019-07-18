#include "ft_printf.h"

char	*g_vector = NULL;
t_f		*g_f = NULL;
int		g_eos = 0;
extern int g_len;

void	ft_else_else(const char **format, va_list ap)
{
	(*format)++;
	parse(format, ap);
	if (g_f->f == 'i' || g_f->f == 'd')
		integer(ap);
	else if (g_f->f == 'o')
		octal(ap);
	else if (g_f->f == 's')
		string(ap);
	else if (g_f->f == 'c' || g_f->f == 'C')
		character(ap, NULL);
	else if (g_f->f == 'X')
		big_hex(ap);
	else if (g_f->f == 'x' || g_f->f == 'p')
		hex(ap);
	else if (g_f->f == 'f')
		f_f(ap);
	else if (g_f->f == '%')
		percent();
	else if (g_f->f == 'u')
		uinteger(ap);
	else if (g_f->f == 'b')
		binary(ap);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_else_else(&format, ap);
		else
		{
			g_vector = ft_vector(g_vector, format, 5, 1);
			format++;
		}
	}
	va_end(ap);
	len = printf_strlen(g_vector, g_eos);
	write(1, g_vector, len);
	if (g_vector)
		ft_strdel(&g_vector);
	free(g_f);
	g_len = 0;
	return (len);
}
//%[флаги][ширина][.точность][размер]тип