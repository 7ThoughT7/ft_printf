#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	res;
	va_list	ap;
	va_start(ap, str);
	t_flags fl;

	res = parser(str, &fl, ap);

//	printf("\n%d\n", fl.minus);
//	printf("%d\n", fl.zero);
//	printf("%d\n", fl.width);
//	printf("%d\n", fl.pr_tion);
//	printf("%d\n", fl.type);
//	printf("%d\n", fl.len);
	va_end(ap);
	return (res);
}