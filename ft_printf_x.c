#include "ft_printf.h"

int negativ_x(unsigned int num, t_flags fl, char space)
{
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', (fl.pr_tion - fl.len));
	ft_putnbr_xfd(num, fl);
	if (fl.width > max(fl.pr_tion, fl.len))
		ft_putchar_fd(space, (fl.width - max(fl.pr_tion, fl.len)));
	return (0);
}

int pozitiv_x(unsigned int num, t_flags fl, char space)
{
	if (fl.pr_tion == -1)
		if (fl.width > max(fl.pr_tion, fl.len))
			ft_putchar_fd(space,fl.width - max(fl.pr_tion, fl.len));
	if (fl.pr_tion >= 0)
		if (fl.width > max(fl.pr_tion, fl.len))
			ft_putchar_fd(space,fl.width - max(fl.pr_tion, fl.len));
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', fl.pr_tion - fl.len);
	ft_putnbr_xfd(num, fl);
	return (0);
}

int ft_printf_x(t_flags fl, unsigned int num)
{
	int		res;
	char	space;

	fl.len = ft_putnbr_x(num, 16);
	if (num == 0 && fl.pr_tion == 0)
	{
		ft_putchar_fd(' ', fl.width);
		return (fl.width);
	}
	res = max(fl.width, max(fl.pr_tion, fl.len));
	space = ' ';
	if (fl.flag == '0' && fl.pr_tion == -1)
		space = '0';
	if (fl.flag == '-')
		negativ_x(num, fl, space);
	else
		pozitiv_x(num, fl, space);
	return (res);
}