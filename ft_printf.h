#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "./libft/libft.h"
#include <stdarg.h>
#include <limits.h>

//#define LIM 1000000000000000000
#define LIM 2000000000000000000
#define DIV 1000000000000000000
#define ZERO 1000000000000000000
#define CLUSTER_SIZE 18

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

struct 			s_double
{
	size_t					m;
	unsigned short			e:15;
	char					s:1;
};

typedef union	u_double
{
	long double				d;
	struct s_double			s;
}				t_double;

typedef struct	s_bigint
{
	size_t	*num;
	int		len;
	int		start;
}				t_bigint;

extern char	*g_vector;
extern t_f	*g_f;
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
t_bigint	get_fraction(size_t man, int pow);
t_bigint	get_whole(size_t man, int pow);
void	f_long_double(va_list ap);
void	f_f(va_list ap);

#endif
