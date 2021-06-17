#include "ft_printf.h"

static int	negativ_u(unsigned int num, t_flags fl, char space)
{
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', (fl.pr_tion - fl.len));
	ft_putnbr_fd(num, 1);
	if (fl.width > max(fl.pr_tion, fl.len))
		ft_putchar_fd(space, (fl.width - max(fl.pr_tion, fl.len)));
	return (0);
}

static int	pozitiv_u(unsigned int num, t_flags fl, char space)
{
	if (fl.pr_tion == -1)
	{
		if (fl.width > max(fl.pr_tion, fl.len))
			ft_putchar_fd(space, fl.width - max(fl.pr_tion, fl.len));
	}
	if (fl.pr_tion >= 0)
		if (fl.width > max(fl.pr_tion, fl.len))
			ft_putchar_fd(space, fl.width - max(fl.pr_tion, fl.len));
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', fl.pr_tion - fl.len);
	ft_putnbr_fd(num, 1);
	return (0);
}

int	ft_printf_u(t_flags fl, unsigned int num)
{
	int		res;
	char	space;

	fl.len = ft_putnbr(num, 10);
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
		negativ_u(num, fl, space);
	else
		pozitiv_u(num, fl, space);
	return (res);
}
