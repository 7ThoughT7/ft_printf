#include "ft_printf.h"

int type_handling(t_flags fl, va_list ap)
{
	int		res;
	int		num;
	char	*str;
	char	c;
	unsigned int	num_u;
	unsigned long	num_p;


	res = 0;
	if (fl.type == 'd' || fl.type == 'i')
	{
		num = va_arg(ap, int);
		res += ft_printf_di(fl, num);
	}
	if (fl.type == 'x' || fl.type == 'X')
	{
		num_u = va_arg(ap, unsigned int);
		res += ft_printf_x(fl, num_u);
	}
	if (fl.type == 's')
	{
		str = va_arg(ap, char *);
		res += ft_printf_s(fl, str);
	}
	if (fl.type == 'u')
	{
		num_u = va_arg(ap, unsigned int);
		res += ft_printf_u(fl, num_u);
	}
	if (fl.type == 'p')
	{
		num_p = va_arg(ap, unsigned long);
		res += ft_printf_p(fl, num_p);
	}
	if (fl.type == 'c')
	{
		c = va_arg(ap, int);
		res += ft_printf_c(fl, c);
	}
	if (fl.type == '%')
		res += ft_printf_c(fl, '%');
	if (fl.type == 0)
		res += (ft_printf_c(fl, ' ') - 1);
	return (res);
}