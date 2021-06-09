#include "ft_printf.h"

int negativ_nbr(int num, t_flags fl, int len, char space, int the_minus)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (fl.pr_tion > len)
		ft_putchar_fd('0', (fl.pr_tion - len));
	ft_putnbr_fd(num, 1);
	if (fl.width > max(fl.pr_tion, len))
		ft_putchar_fd(space, (fl.width - max(fl.pr_tion, len) - the_minus));
	return (0);
}

int pozitiv_nbr(int num, t_flags fl, int len, char space, int the_minus)
{
	if (fl.width > max(fl.pr_tion, len))
		ft_putchar_fd(space,fl.width - max(fl.pr_tion, len) - the_minus);
	if (num < 0 && (space == 0 || fl.pr_tion >= fl.width))
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (num < 0 && (space == 0 || (fl.pr_tion <= fl.width && fl.pr_tion != 0)))
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (fl.pr_tion > len)
		ft_putchar_fd('0', fl.pr_tion - len);
	ft_putnbr_fd(num, 1);
	return (0);
}

int	ft_printf_di(t_flags fl, int num)
{
	int 	res;
	int 	len;
	int		the_minus;
	char	space;

	len = ft_putnbr(num, 10);
	the_minus = 0;
	if (len == 0 && fl.pr_tion == 0)
	{
		ft_putchar_fd(' ', fl.width);
		return (fl.width);
	}
	if (fl.pr_tion == 0 && num == 0)
		return (0);
	if (num < 0)
		the_minus = 1;
	res = max(fl.width,max(fl.pr_tion + the_minus,len + the_minus));
	space = ' ';
	if (fl.flag == '0' && fl.pr_tion == -1)
		space = '0';
	if (fl.flag == '-')
		negativ_nbr(num, fl, len, space, the_minus);
	else
		pozitiv_nbr(num, fl, len, space, the_minus);
	return (res);
}