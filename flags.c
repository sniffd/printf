#include "ft_printf.h"
#define S *s

void	parse_flags(char s, t_f *f)
{
	if (s == '#')
		f->okt = 1;
	else if (s == '-')
		f->min = 1;
	else if (s == '+')
		f->plu = 1;
	else if (s == ' ')
		f->spc = 1;
	else if (s == '0')
		f->zer = 1;
}

t_f	*parse(char **s, va_list ap)
{
	t_f *f;
	int	zone;

	if (!(f = (t_f *)ft_memalloc(sizeof(t_f))))
		return 0;
	zone = 0;
	if ((*S >= 49 && *S <= 57) || *S == '*')
		zone = 1;
	else if (*S == '.')
		zone = 2;
	else if (*S == 'l' || *S == 'h' || *S == 'L')//TODO добавить обработку ширины, доделать обработку точности (?)
	while (*S != 'd' && *S != 'i' && *S != 'o' &&
	*S != 'u' && *S != 'x' && *S != 'X' && *S != 'f' &&
	*S != 'c' && *S != 's' && *S != 'p' && *S != '%')
	{
		parse_flags(**s, f);
		if ()
		if (*S == '.')
		{
			if (*(*s + 1) == '*')
				f->dot = va_arg(ap, int);
			else
				f->dot = ft_atoi(*s + 1);
		}
		if (*S == 'L')
			f->bl = 1;
		if (*S == 'l')
		{
			f->ll = f->l == 1 ? 1 : 0;
			f->l = 1;
		}
		if (*S == 'h')
		{
			f->hh = f->h == 1 ? 1 : 0;
			f->h = 1;
		}
	}
}