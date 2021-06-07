#include "ft_printf.h"

int type_handling(t_flags fl, int num)
{
	int	res;

	res = 0;
	if (fl.type == 'd')
		res += ft_printf_di(fl, num);

	return (res);
}