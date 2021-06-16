#include "ft_printf.h"

int type_handling(t_flags fl, va_list ap)
{
	int				res;
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
		num = va_arg(ap, unsigned int);
		res += ft_printf_x(fl, num);
	}
	if (fl.type == 's')
	{
		str = va_arg(ap, char *);
		res += ft_printf_sc(fl, str);
	}
	if (fl.type == 'u')
	{
		num = va_arg(ap, unsigned int);
		res += ft_printf_u(fl, num);
	}
	if (fl.type == 'p')
	{
		num = va_arg(ap, unsigned int);
		res += ft_printf_p(fl, num);
	}
	return (res);
}