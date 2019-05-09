#include "ft_printf.h"

void	print_sign(long long number, int plu, int spc)
{
	if (number < 0)
		vector = ft_vector(vector, "-", 5, 0);
	else if (plu)
		vector = ft_vector(vector, "+", 5, 0);
	else if (spc)
		vector = ft_vector(vector, " ", 5, 0);
}

void	minus(long long arg, int len, char *in)
{
	int	tmplen;

	print_sign(arg, f->plu, f->spc);
	tmplen = f->pre - len;
	oktotorp(arg, len);
	if (tmplen <= 0)
	{
		vector = ft_vector(vector, in, 5, 0);
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - len - 1 :
			f->wid - len;
		addcharn(' ', tmplen);
	}
	else
	{
		addcharn('0', tmplen);
		vector = ft_vector(vector, in, 5, 0);
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
			f->wid - f->pre;
		addcharn(' ', tmplen);
	}
}

void	precision(long long arg, int len, char *in)
{
	int	tmplen;

	if (f->pre >= len)
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
			f->wid - f->pre;
	else
		tmplen = (f->plu || f->spc || arg < 0) ? f->wid - len - 1 :
			f->wid - len;
	if (tmplen <= 0 && oktotorp(arg, len))
	{
		tmplen = f->pre - len;
		print_sign(arg, f->plu, f->spc);
		addcharn('0', tmplen);
		vector = ft_vector(vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		tmplen = f->pre - len;
		print_sign(arg, f->plu, f->spc);
		oktotorp(arg, len);
		addcharn('0', tmplen);
		in = !(!f->pre && !arg) ? in : " ";
		vector = ft_vector(vector, in, 5, 0);
	}
}

void	zero_and_else(long long arg, char *in, int tmplen)
{
	int	len;

	len = (int)ft_strlen(in);
	if (f->zer && !(f->dot))
	{
		print_sign(arg, f->plu, f->spc);
		oktotorp(arg, len);
		addcharn('0', tmplen);
		vector = ft_vector(vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		print_sign(arg, f->plu, f->spc);
		oktotorp(arg, len);
		vector = ft_vector(vector, in, 5, 0);
	}
}

void	integer(va_list ap)
{
	if (f->hh)
		int_char(ap);
	else if (f->h)
		int_short(ap);
	else if (f->ll)
		int_long_long(ap);
	else if (f->l)
		int_long(ap);
	else
		int_int(ap);
}
