#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{

	printf("Test, %-+20.10i\n", -100);
	ft_printf("Test, %-+20.10i\n", -100);
	printf("Test, %-+20.10i\n", 100);
	ft_printf("Test, %-+20.10i\n", 100);
	return 0;
}