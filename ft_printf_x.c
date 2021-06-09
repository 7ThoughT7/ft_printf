#include "ft_printf.h"

int ft_printf_x(t_flags fl, int num)
{
	int res;
	int	len;

	res = 0;
	len = ft_putnbr(num, 16);
	if (len == 0 && fl.pr_tion == 0)
	{
		ft_putchar_fd(' ', fl.width);
		return (fl.width);
	}


	return (res);
}