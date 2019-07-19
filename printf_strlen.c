#include "ft_printf.h"

size_t	printf_strlen(const char *s, int n)
{
	const char	*str;

	str = s;
	while (*s || n)
	{
		if (*s == '\0')
			n--;
		s++;
	}
	return (s - str);
}
