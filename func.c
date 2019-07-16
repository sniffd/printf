#include "ft_printf.h"

void	finish(const char **s)
{
	if ((*S == 'd' || *S == 'i' || *S == 'o' || *S == 'u' || *S == 'x' ||
		 *S == 'X' || *S == 'f' || *S == 'c' || *S == 's' || *S == 'p' ||
		 *S == '%' || *S == 'C' || *S == 'b'))
		g_f->f = *S;
	else
		character(NULL, (char *)S);
	(S)++;
}
