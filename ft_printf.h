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
extern char	*vector;
extern t_f	*f;
void	addcharn(char c, ssize_t n);
int	ft_printf(const char *format, ...);
t_f	*parse(const char **s, va_list ap);
void integer(va_list ap);
void	print_sign(long long number, int plu, int spc);
void minus(long long arg, int len, char *in);
void precision(long long arg, int len, char *in);
void zero_and_else(long long arg, char *in, int tmplen);
int oktotorp(unsigned long long arg, int len);
void int_char(va_list ap);
void int_short(va_list ap);
void int_int(va_list ap);
void int_long(va_list ap);
void int_long_long(va_list ap);
void o_char(va_list ap);
void o_short(va_list ap);
void o_int(va_list ap);
void o_long(va_list ap);
void o_long_long(va_list ap);
void big_x_char(va_list ap);
void big_x_short(va_list ap);
void big_x_int(va_list ap);
void big_x_long(va_list ap);
void big_x_long_long(va_list ap);
void x_char(va_list ap);
void x_short(va_list ap);
void x_int(va_list ap);
void x_long(va_list ap);
void x_long_long(va_list ap);
void octal(va_list ap);
void hex(va_list ap);
void big_hex(va_list ap);
void string(va_list ap);
void character(va_list ap);

#endif
