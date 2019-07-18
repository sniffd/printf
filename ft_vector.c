#include "ft_printf.h"

int g_len;

void		nullcpy(char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	if (g_f && g_f->flg)
	{
		g_eos++;
		g_f->flg = 0;
	}
}

void		nullcat(char *s1, const char *s2, size_t len)
{
	nullcpy(s1 + g_len, s2, len);
}

char		*ft_if(char **vector, const char *str, size_t *size, size_t len)
{
	char	*ret;

	while (ft_strlen(*vector) + 1 + ft_strlen(str) >= *size)
		*size *= 2;
	if (!(ret = ft_memalloc(*size)))
		exit(0);
	ft_strcpy(ret, *vector);
	if (!len)
	{
		ft_strcat(ret, str);
		g_len += ft_strlen(str);
	}
	else
	{
		nullcat(ret, str, len);
		g_len += len;
	}
	free(*vector);
	return (ret);
}

char		*ft_else(char **vector, const char *str, size_t *size, size_t len)
{
	if (ft_strlen(*vector) + 1 + ft_strlen(str) >= *size)
		return (ft_if(vector, str, size, len));
	else
	{
		if (!len)
		{
			ft_strcat(*vector, str);
			g_len += ft_strlen(str);
		}
		else
		{
			nullcat(*vector, str, len);
			g_len += len;
		}
		return (*vector);
	}
}

char		*ft_vector(char *vector, const char *str, size_t i_size, size_t len)
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
		{
			ft_strcpy(ret, str);
			g_len += ft_strlen(str);
		}
		else
		{
			nullcpy(ret, str, len);
			g_len += len;
		}
		return (ret);
	}
	else
		return (ft_else(&vector, str, &size, len));
}
