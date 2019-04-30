#include "ft_printf.h"
#include <stdio.h>

void	int_test(void)
{
	printf("% 20.10i\n", -100);
	ft_printf("% 20.10i\n", -100);
	printf("% 20.10i\n", 100);
	ft_printf("% 20.10i\n", 100);
	printf("% d\n", 123125);
	ft_printf("% d\n", 123125);
	printf("%+d\n", 123125);
	ft_printf("%+d\n", 123125);
	printf("%010d\n", 123125);
	ft_printf("%010d\n", 123125);
	printf("%-10d\n", 123125);
	ft_printf("%-10d\n", 123125);
	printf("%-+10d\n", 123125);
	ft_printf("%-+10d\n", 123125);
	printf("% -10d\n", 123125);
	ft_printf("% -10d\n", 123125);
	printf("% 010d\n", 123125);
	ft_printf("% 010d\n", 123125);
	printf("%3.2d\n", 0);
	ft_printf("%3.2d\n", 0);
	printf("% d\n", 12);
	ft_printf("% d\n", 12);
	printf("%+d\n", 12);
	ft_printf("%+d\n", 12);
	printf("%010d\n", 12);
	ft_printf("%010d\n", 12);
	printf("%-10d\n", 12);
	ft_printf("%-10d\n", 12);
	printf("%-+10d\n", 12);
	ft_printf("%-+10d\n", 12);
	printf("% -10d\n", 12);
	ft_printf("% -10d\n", 12);
	printf("% 010d\n", 12);
	ft_printf("% 010d\n", 12);
	printf("%+010d\n", 12);
	ft_printf("%+010d\n", 12);
	printf("% d\n", -123125);
	ft_printf("% d\n", -123125);
	printf("%+d\n", -123125);
	ft_printf("%+d\n", -123125);
	printf("%010d\n", -123125);
	ft_printf("%010d\n", -123125);
	printf("%-10d\n", -123125);
	ft_printf("%-10d\n", -123125);
	printf("%-+10d\n", -123125);
	ft_printf("%-+10d\n", -123125);
	printf("% -10d\n", -123125);
	ft_printf("% -10d\n", -123125);
	printf("% 010d\n", -123125);
	ft_printf("% 010d\n", -123125);
	printf("%+010d\n", -123125);
	ft_printf("%+010d\n", -123125);
	printf("%d\n", 123125);
	ft_printf("%d\n", 123125);
	printf("%hhd\n", 123125);
	ft_printf("%hhd\n", 123125);
	printf("%hd\n", 123125);
	ft_printf("%hd\n", 123125);
	printf("%ld\n", 123125);
	ft_printf("%ld\n", 123125);
	printf("%lld\n", 123125);
	ft_printf("%lld\n", 123125);
}