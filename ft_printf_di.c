#include "ft_printf.h"

static long	num_long(int num)
{
	long	num_l;

	num_l = num;
	ft_putchar_fd('-', 1);
	num_l *= -1;
	return (num_l);
}

static int	negativ_nbr(int num, t_flags fl, char space, int minus)
{
	long	num_l;

	num_l = num;
	if (num < 0)
		num_l = num_long(num);
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', (fl.pr_tion - fl.len));
	ft_putnbr_fd(num_l, 1);
	if (fl.width > max(fl.pr_tion, fl.len))
		ft_putchar_fd(space, (fl.width - max(fl.pr_tion, fl.len) - minus));
	return (0);
}

static int	pozitiv_nbr(int num, t_flags fl, char space, int minus)
{
	long	num_l;

	num_l = num;
	if (fl.pr_tion <= -1)
	{
		if (num < 0 && space == '0')
			num_l = num_long(num);
		if (fl.width > max(fl.pr_tion, fl.len))
			ft_putchar_fd(space, fl.width - max(fl.pr_tion, fl.len) - minus);
		if (num < 0 && space == ' ')
			num_l = num_long(num);
	}
	if (fl.pr_tion >= 0)
	{
		if (fl.width > max(fl.pr_tion, fl.len))
			ft_putchar_fd(space, fl.width - max(fl.pr_tion, fl.len) - minus);
		if (num < 0)
			num_l = num_long(num);
	}
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', fl.pr_tion - fl.len);
	ft_putnbr_fd(num_l, 1);
	return (0);
}

int	ft_printf_di(t_flags fl, int num)
{
	int		res;
	int		minus;
	char	space;

	fl.len = ft_putnbr(num, 10);
	minus = 0;
	if (num == 0 && fl.pr_tion == 0)
	{
		ft_putchar_fd(' ', fl.width);
		return (fl.width);
	}
	if (num < 0)
		minus = 1;
	res = max(fl.width, max(fl.pr_tion + minus, fl.len + minus));
	space = ' ';
	if (fl.flag == '0' && fl.pr_tion <= -1)
		space = '0';
	if (fl.flag == '-')
		negativ_nbr(num, fl, space, minus);
	else
		pozitiv_nbr(num, fl, space, minus);
	return (res);
}
