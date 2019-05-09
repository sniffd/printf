#include "libft.h"

char	*ft_itoa_base(unsigned int n, int base)
{
	char			*dic;
	char			*res;
	int				i;
	unsigned int	nb;

	dic = ft_strdup("0123456789ABCDEF");
	i = 1;
	nb = n;
	while ((nb = nb / base))
		i++;
	if (!(res = (char *)ft_memalloc(i-- + 1)))
		return (0);
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[i--] = dic[n % base];
		n = n / base;
	}
	free(dic);
	return (res);
}
