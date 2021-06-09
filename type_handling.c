#include "ft_printf.h"

int type_handling(t_flags fl, int num)
{
	int	res;

	res = 0;
	if (fl.type == 'd' || fl.type == 'i')
		res += ft_printf_di(fl, num);
	if (fl.type == 'x')
		res += ft_printf_x(fl, num);
	return (res);
}