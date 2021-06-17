#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_flags	fl;

	va_start(ap, str);
	res = parser(str, &fl, ap);
	va_end(ap);
	return (res);
}
