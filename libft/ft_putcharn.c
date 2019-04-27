#include "libft.h"

void	ft_putcharn(char c, ssize_t	n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
}