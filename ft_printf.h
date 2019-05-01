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
	int		pre;
	int		wid;
	char	f;
}				t_f;
int	ft_printf(const char *format, ...);
t_f	*parse(const char **s, va_list ap);
int	integer(t_f *f, va_list	ap);
void	print_sign(long long number, int plu, int spc);
void	minus(long long arg, int len, char *in, t_f *f);
void	precision(long long arg, int len, char *in, t_f *f);
void	zero_and_else(long long arg, char *in, int tmplen, t_f *f);
int		int_char(t_f *f, va_list ap);
int		int_short(t_f *f, va_list ap);
int		int_int(t_f *f, va_list ap);
int		int_long(t_f *f, va_list ap);
int		int_long_long(t_f *f, va_list ap);
int		string(va_list ap, t_f *f);
int		character(va_list ap, t_f *f);

#endif
