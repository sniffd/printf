#include "ft_printf.h"


int	integer(t_f *f, va_list	ap)
{
	char	*in;
	int 	len;
	int 	arg;

	arg = va_arg(ap, int);
	in = ft_itoa((int)ft_abs(arg));
	len = (f->plu || f->spc || arg < 0) ? f->wid - (long)ft_strlen(in) - 1 :
			f->wid - (long)ft_strlen(in);
	if (len <= 0)
	{
		if (arg < 0)
			ft_putchar('-');
		else if (f->plu)
			ft_putchar('+');
		else if (f->spc)
			ft_putchar(' ');
		len = f->pre - (long)ft_strlen(in);
		while (len > 0)
		{
			ft_putchar('0');
			len--;
		}
		ft_putstr(in);
	}
	else if (f->zer && !(f->min) && !(f->dot))
	{
		if (arg < 0)
			ft_putchar('-');
		else if (f->plu)
			ft_putchar('+');
		else if (f->spc)
			ft_putchar(' ');
		while (len > 0)
		{
			ft_putchar('0');
			len--;
		}
		ft_putstr(in);
	}
	else if (f->dot || f->wid)
	{
		if (f->min)
		{
			if (f->plu && arg >= 0)
				ft_putchar('+');
			else if (arg < 0)
				ft_putchar('-');
			else if (f->spc)
				ft_putchar(' ');
			if ((f->pre - (long)ft_strlen(in)) > 0)
			{
				len = f->wid - (f->pre - (long)ft_strlen(in));
				if (len > 0)
				{
					len = f->pre - (long)ft_strlen(in);
					while (len > 0)
					{
						ft_putchar('0');
						len--;
					}
					len = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
							f->wid - f->pre;
					ft_putstr(in);
					while (len > 0)
					{
						ft_putchar(' ');
						len--;
					}
				}
			}
			else
				ft_putstr(in);
			while (len > 0)
			{
				ft_putchar(' ');
				len--;
			}
		}
		else
		{
			len = (f->plu || f->spc || arg < 0) ? f->wid - f->pre - 1 :
				  f->wid - f->pre;
			while (len > 0)
			{
				ft_putchar(' ');
				len--;
			}
			if (arg < 0)
				ft_putchar('-');
			else if (f->plu)
				ft_putchar('+');
			len = f->pre - (long)ft_strlen(in);
			while (len > 0)
			{
				ft_putchar('0');
				len--;
			}
			ft_putstr(in);
		}
	}
	return (0);
}