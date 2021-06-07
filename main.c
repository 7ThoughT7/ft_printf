#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int or = printf("or:[%d]\n", -1);
	printf("len or: %d\n", or);
	int cp =ft_printf("cp:[%d]\n", -1);
	printf("len cp: %d\n", cp);
	return (0);
}