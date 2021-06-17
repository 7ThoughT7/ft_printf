#include "ft_printf.h"

static int	type_hand1(t_flags fl, va_list ap)
{
	int	num;
	int	num_u;
	int	res;

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
	return (res);
}

static int	type_hand2(t_flags fl, va_list ap)
{
	char			*str;
	unsigned int	num_u;
	unsigned long	num_p;
	int				res;

	res = 0;
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
	return (res);
}

int	type_handling(t_flags fl, va_list ap)
{
	int		res;
	char	c;

	res = 0;
	if (fl.type == 'c')
	{
		c = va_arg(ap, int);
		res += ft_printf_c(fl, c);
	}
	if (fl.type == 'd' || fl.type == 'i' || fl.type == 'x' || fl.type == 'X')
		res += type_hand1(fl, ap);
	if (fl.type == 's' || fl.type == 'u' || fl.type == 'p')
		res += type_hand2(fl, ap);
	if (fl.type == '%')
		res += ft_printf_c(fl, '%');
	return (res);
}
