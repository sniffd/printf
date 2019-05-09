#include "libft.h"

char	*ft_strtolower(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	return (str);
}
