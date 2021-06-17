#include "ft_printf.h"

int	ft_printf_c(t_flags fl, char c)
{
	char space;
	int res;

	space = ' ';
	res = max(fl.width, 1);
	if (fl.flag == '0')
		space = '0';
	if (fl.flag == '-')
	{
		ft_putchar_fd(c, 1);
		ft_putchar_fd(space, (fl.width - 1));
	}
	else
	{
		ft_putchar_fd(space, (fl.width - 1));
		ft_putchar_fd(c, 1);
	}
	return (res);
}