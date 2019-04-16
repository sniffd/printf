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

void	parse_size(char s, t_f *f)
{
	if (s == 'L')
		f->bl = 1;
	if (s == 'l')
	{
		f->ll = f->l == 1 ? 1 : 0;
		f->l = 1;
	}
	if (s == 'h')
	{
		f->hh = f->h == 1 ? 1 : 0;
		f->h = 1;
	}
}

void	parse_dot_or_wid(char *s, t_f *f, va_list ap, int flag)
{
	if (flag)
	{
		if (S == '.')
		{
			if (*(s + 1) == '*')
				f->dot = va_arg(ap, int);
			else
				f->dot = ft_atoi(s + 1);
		}
	}
	else
	{
		if (S == '*')
			f->wid = va_arg(ap, int);
		else if (!(f->wid))
			f->wid = ft_atoi(s);
	}
}

int	parse_zone(char s, int zone)
{
	if (zone < 1 && ((s >= 49 && s <= 57) || s == '*'))
		zone = 1;
	else if (zone < 2 && s == '.')
		zone = 2;
	else if (zone < 3 && (s == 'l' || s == 'h' || s == 'L'))
		zone = 3;
	return (zone);
}

t_f	*parse(char **s, va_list ap)
{
	t_f *f;
	int	zone;

	if (!(f = (t_f *)ft_memalloc(sizeof(t_f))))
		return 0;
	zone = 0;
	while (*S != 'd' && *S != 'i' && *S != 'o' && *S != 'u' && *S != 'x' &&
	*S != 'X' && *S != 'f' && *S != 'c' && *S != 's' && *S != 'p' && *S != '%')
	{
		zone = parse_zone(*S, zone);
		if (zone == 0)
			parse_flags(**s, f);
		else if (zone == 1)
			parse_dot_or_wid(S, f, ap, 0);
		else if (zone == 2)
			parse_dot_or_wid(S, f, ap, 1);
		else
			parse_size(**s, f);
		(S)++;
	}
	f->f = *S;
	return (f);
}