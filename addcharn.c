#include "ft_printf.h"

void	addcharn(char c, ssize_t n)
{
	while (n > 0)
	{
		g_vector = ft_vector(g_vector, &c, 5, 1);
		n--;
	}
}
