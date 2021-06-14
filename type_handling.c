#include "ft_printf.h"

int type_handling(t_flags fl, va_list ap)
{
	int				res;
	unsigned int	num_x;
	int				num;
	char			*str;

	res = 0;
	if (fl.type == 'd' || fl.type == 'i')
	{
		num = va_arg(ap, int);
		res += ft_printf_di(fl, num);
	}
	if (fl.type == 'x' || fl.type == 'X')
	{
		num_x = (unsigned int)num;
		res += ft_printf_x(fl, num_x);
	}
	if (fl.type == 's')
	{
		str = va_arg(ap, char *);
		res += ft_printf_sc(fl, str);
	}
	return (res);
}