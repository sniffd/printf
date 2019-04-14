#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef	struct	s_f
{
	int		plu;
	int		min;
	int		zer;
	int 	spc;
	int 	okt;
	int 	h;
	int 	hh;
	int 	l;
	int 	ll;
	int		bl;
	int		dot;
	int		wid;
	char	f;
}				t_f;
int	ft_printf(const char *format, ...);

#endif
