#include "ft_printf.h"

void	printsign(int number, int plu, int spc)
{
	if (number < 0)
		ft_putchar('-');
	else if (plu)
		ft_putchar('+');
	else if (spc)
		ft_putchar(' ');
}

int	integer(t_f *f, va_list	ap)
{
	char	*in;
	int 	len;
	int 	arg;

	arg = va_arg(ap, int);
	in = ft_itoa((int)ft_abs(arg));
	len = (f->plu || f->spc || arg < 0) ? f->wid - (int)ft_strlen(in) - 1 :
			f->wid - (int)ft_strlen(in);
	if (len <= 0)
	{
		printsign(arg, f->plu, f->spc);
		len = f->pre - (int)ft_strlen(in);
		ft_putcharn('0', len);
		ft_putstr(in);
	}
	else if (f->min)
	{
		printsign(arg, f->plu, f->spc);
		len = f->pre - (int)ft_strlen(in);
		if (len <= 0)
		{
			ft_putstr(in);
			len = (f->plu || f->spc || arg < 0) ? f->wid -
				(int)ft_strlen(in) - 1 : f->wid - (int)ft_strlen(in);
			ft_putcharn(' ', len);
		}
		else
		{
			ft_putcharn('0', len);
			ft_putstr(in);
			len = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
					f->wid - f->pre;
			ft_putcharn(' ', len);
		}
	}
	else if (f->dot)
	{
		if (f->pre >= (int)ft_strlen(in))
			len = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
					f->wid - f->pre;
		else
			len = (f->plu || f->spc || arg < 0) ? f->wid - (int)ft_strlen(in) -
					1 : f->wid - (int)ft_strlen(in);
		if (len <= 0)
		{
			len = f->pre - (int)ft_strlen(in);
			printsign(arg, f->plu, f->spc);
			ft_putcharn('0', len);
			ft_putstr(in);
		}
		else
		{
			ft_putcharn(' ', len);
			len = f->pre - (int)ft_strlen(in);
			printsign(arg, f->plu, f->spc);
			ft_putcharn('0', len);
			ft_putstr(in);
		}
	}
	else if (f->zer && !(f->dot))
	{
		printsign(arg, f->plu, f->spc);
		ft_putcharn('0', len);
		ft_putstr(in);
	}
	else
	{
		ft_putcharn(' ', len);
		printsign(arg, f->plu, f->spc);
		ft_putstr(in);
	}
	return (0);
}