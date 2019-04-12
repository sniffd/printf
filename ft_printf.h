#ifndef FT_PRINTF_H
#define FT_PRINTF_H

typedef	struct	s_f
{
	int	plu;
	int	min;
	int	zer;
	int spc;
	int okt;
	int h;
	int hh;
	int l;
	int ll;
	int bl;
}				t_f;
int	ft_printf(const char *format, ...);

#endif
