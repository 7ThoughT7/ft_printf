#include "ft_printf.h"

static int	negativ_p(unsigned long num, t_flags fl, char space, char *ox)
{
	ft_putstr_fd(ox, 2);
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', (fl.pr_tion - fl.len));
	ft_putnbr_xfd(num, fl);
	if (fl.width > max(fl.pr_tion, fl.len + 2))
		ft_putchar_fd(space, (fl.width - (max(fl.pr_tion, fl.len) + 2)));
	return (0);
}

static int	pozitiv_p(unsigned long num, t_flags fl, char space, char *ox)
{
	if (fl.pr_tion <= -1)
	{
		if (fl.width > max(fl.pr_tion, fl.len + 2))
		{
			ft_putchar_fd(space, fl.width - max(fl.pr_tion, fl.len) - 2);
			ft_putstr_fd(ox, 2);
		}
		else
			ft_putstr_fd(ox, 2);
	}
	if (fl.pr_tion >= 0)
	{
		if (fl.width > max(fl.pr_tion, fl.len + 2))
			ft_putchar_fd(space, fl.width - max(fl.pr_tion, fl.len) - 2);
		ft_putstr_fd(ox, 2);
	}
	if (fl.pr_tion > fl.len)
	{
		ft_putchar_fd('0', fl.pr_tion - fl.len);
	}
	ft_putnbr_xfd(num, fl);
	return (0);
}

static int	num_zero(t_flags fl, char *ox)
{
	int	res;

	if (fl.flag == '-')
	{
		ft_putstr_fd(ox, 2);
		ft_putchar_fd(' ', fl.width - 2);
	}
	else
	{
		ft_putchar_fd(' ', fl.width - 2);
		ft_putstr_fd(ox, 2);
	}
	res = max(fl.width, 2);
	return (res);
}

int	ft_printf_p(t_flags fl, unsigned long num)
{
	int		res;
	char	space;
	char	*ox;

	ox = "0x";
	fl.len = ft_putnbr_x(num, 16);
	res = max(fl.width, max(fl.pr_tion, fl.len) + 2);
	space = ' ';
	if (fl.flag == '0' && fl.pr_tion == -1)
		space = '0';
	if (num == 0 && fl.pr_tion == 0)
	{
		res = num_zero(fl, ox);
		return (res);
	}
	if (fl.flag == '-')
		negativ_p(num, fl, space, ox);
	else
		pozitiv_p(num, fl, space, ox);
	return (res);
}
