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
	int 	flg;
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
	char	sign;
}				t_bigint;

typedef struct	s_round
{
	int	index;
	int	nmb_pos;
	int next_digit;
	size_t	mask;
}				t_round;

typedef enum
{
	NORM,
	INF,
	NAN,
	DENORM
}	t_nan;

extern char	*g_vector;
extern t_f	*g_f;
extern int	g_eos;
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
t_bigint check_overflow_five(t_bigint b, int i);
void	print(t_bigint f, t_bigint w, int index, int nmb_pos);
t_bigint	get_null(void);
int	normal_check(struct s_double d);
void	print_nan(int nan, char sign);
void	f_print_sign(char sign, int plu, int spc);
void	percent(void);
void	uint_char(va_list ap);
void	uint_short(va_list ap);
void	uint_int(va_list ap);
void	uint_long(va_list ap);
void	uint_long_long(va_list ap);
void	uinteger(va_list ap);
void	b_char(va_list ap);
void	b_short(va_list ap);
void	b_int(va_list ap);
void	b_long(va_list ap);
void	b_long_long(va_list ap);
void	binary(va_list ap);
size_t	printf_strlen(const char *s, int n);
char			*ft_vector(char *vector, const char *str, size_t i_size,
						   size_t len);
void	f_round(t_bigint w, t_bigint f);
void	fraction_select_round(t_bigint *f, t_round *r, char flag);
void	whole_select_round(t_bigint *f, t_bigint *w, t_round *r, char flag);
size_t	get_mask(int i);
void	math_round(t_bigint *b, t_round *r, char flag);
void	check_zero(t_bigint *f, t_round *r, int len, char flag);
void			while_i_less_biggistlen(t_bigint *res, t_bigint a, t_bigint b, int i);
int			if_i_biggest_lim(t_bigint *res, int i, t_bigint a, t_bigint b);
int			if_or_else(t_bigint *res, t_bigint a, t_bigint b, int *i);
t_bigint	check_overflow(t_bigint b, int i);
t_bigint	pow_of_five(int pow);
void		power_of_five(int pow, int p, int i, t_bigint *b);
t_bigint	bigint_multy_five(t_bigint b);
void		multy_two(t_bigint *res, t_bigint b, int i);

#endif
