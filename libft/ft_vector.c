#include "libft.h"

char	*ft_vector(char *vector , const char *str, size_t i_size)
{
	static size_t	size;
	char			*ret;

	if (!size)
		size = i_size;
	if (!vector)
	{
		size = ft_strlen(str) >= size ? ft_strlen(str) : size;
		ret = ft_memalloc(size + 1);
		ft_strcpy(ret, str);
		return (ret);
	}
	else
	{
		if (ft_strlen(vector) + ft_strlen(str) >= size)
		{
			size *= 2;
			ret = ft_memalloc(size);
			ft_strcpy(ret, vector);
			ft_strcat(ret, str);
			free(vector);
			return (ret);
		}
		else
		{
			ft_strcat(vector, str);
			return (vector);
		}
	}
}