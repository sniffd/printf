#include "ft_printf.h"


int	integer(t_f *f, va_list	ap)
{
	char	*in;
	int		i;
	int 	len;
	int 	arg;

	i = 0;
	arg = va_arg(ap, int);
	in = ft_itoa((int)ft_abs(arg));
	len = f->wid - ft_strlen(in);
	if (len <= 0)
	{
		if (arg < 0)
			ft_putchar('-');
		else if (f->plu)
			ft_putchar('+');
		else if (f->spc)
			ft_putchar(' ');
		len = f->pre - ft_strlen(in);
		if (len > 0)
		{
			while (i < len)
			{
				ft_putchar('0');
				i++;
			}
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
		while (i < len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putstr(in);
	}
	else if (f->dot)
	{
		if (f->min)
		{
			if (f->plu && arg >= 0)
				ft_putchar('+');
			else if (arg < 0)
				ft_putchar('-');
			if ((f->pre - ft_strlen(in)) > 0)
			{
				len = f->wid - (f->pre - ft_strlen(in));
				if (len > 0)
				{
					len = f->pre - ft_strlen(in);
					while (len > 0)
					{
						ft_putchar('0');
						len--;
					}
					len = (arg <= 0) || (f->plu) ? f->wid - f->pre - 1 :
							f->wid - f->pre;
					ft_putstr(in);
					while (len > 0)
					{
						ft_putchar(' ');
						len--;
					}
				}
			}
			else if (arg)
				ft_putstr(in);
			while (i < len)
			{
				ft_putchar(' ');
				i++;
			}
		}
		else
		{
			while (i < len)
			{
				ft_putchar(' ');
				i++;
			}
			if (arg)
				ft_putstr(in);
		}
	}
	return (0);
}