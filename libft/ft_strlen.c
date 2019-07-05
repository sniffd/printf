/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:30:36 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/02/04 12:32:24 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

//size_t	ft_strlen(const char *s)
//{
//	const char	*str;
//
//	str = s;
//	while (*s)
//		s++;
//	return (s - str);
//}

static const char	*byte_zero(const unsigned long *longword_ptr,
								unsigned long lomagic, unsigned long himagic)
{
	unsigned long			longword;
	const char				*cp;
	int						i;

	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic))
		{
			i = 0;
			cp = (const char *)(longword_ptr - 1);
			while (i < 4)
			{
				if (!cp[i])
					return (cp + i);
				++i;
			}
			if (sizeof(longword) > 4)
				while (i < 8)
					if (!cp[i++])
						return (cp + i - 1);
		}
	}
}

size_t				ft_strlen(const char *str)
{
	const char				*char_ptr;
	const unsigned long		*longword_ptr;
	unsigned long			longword;
	unsigned long			himagic;
	unsigned long			lomagic;

	char_ptr = str;
	while ((unsigned long int)char_ptr & (sizeof(longword) - 1))
		if (!(*char_ptr++))
			return (char_ptr - str - 1);
	longword_ptr = (unsigned long *)char_ptr;
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof(longword) > 8)
		abort();
	else if (sizeof(longword) > 4)
	{
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
	return (byte_zero(longword_ptr, lomagic, himagic) - str);
}
