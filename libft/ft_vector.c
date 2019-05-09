#include "libft.h"

char	*ft_else(char **vector, const char *str, size_t *size, size_t len)
{
	char	*ret;

	if (ft_strlen(*vector) + ft_strlen(str) >= *size)
	{
		*size *= 2;
		if (!(ret = ft_memalloc(*size)))
			exit(0);
		ft_strcpy(ret, *vector);
		if (!len)
			ft_strcat(ret, str);
		else
			ft_strncat(ret, str, len);
		free(*vector);
		return (ret);
	}
	else
	{
		if (!len)
			ft_strcat(*vector, str);
		else
			ft_strncat(*vector, str, len);
		return (*vector);
	}
}

char	*ft_vector(char *vector, const char *str, size_t i_size, size_t len)
{
	static size_t	size;
	char			*ret;

	if (!size)
		size = i_size;
	if (!vector)
	{
		size = ft_strlen(str) >= size ? ft_strlen(str) : size;
		if (!(ret = ft_memalloc(size + 1)))
			exit(0);
		if (!len)
			ft_strcpy(ret, str);
		else
			ft_strncpy(ret, str, len);
		return (ret);
	}
	else
		return (ft_else(&vector, str, &size, len));
}
