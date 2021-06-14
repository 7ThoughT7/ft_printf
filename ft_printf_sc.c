#include "ft_printf.h"

int negativ_str(char *str, t_flags fl, char space)
{
	if (fl.pr_tion > fl.len)
		ft_putchar_fd('0', (fl.pr_tion - fl.len));
	if (fl.width > max(fl.pr_tion, fl.len))
		ft_putchar_fd(space, (fl.width - max(fl.pr_tion, fl.len)));
	return (0);
}

int pozitiv_str(char *str, t_flags fl, char space)
{
	return (0);
}

int	ft_printf_sc(t_flags fl, char *str)
{
	int 	res;
	char	space;

	fl.len = ft_strlen(str);
	if (str == 0)
	{
		ft_putchar_fd(' ', fl.width);
		return (fl.width);
	}
	res = max(fl.width, max(fl.pr_tion, fl.len));
	space = ' ';
	if (fl.flag == '0')
		space = '0';
	if (fl.flag == '-')
		negativ_str(str, fl, space);
	else
		pozitiv_str(str, fl, space);
	return (res);
}