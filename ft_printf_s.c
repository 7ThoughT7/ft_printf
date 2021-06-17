#include "ft_printf.h"

static int	negativ_str(char *str, t_flags fl, char space)
{
	if (fl.pr_tion >= 0 && fl.pr_tion < fl.len)
	{
		ft_putstr_fd(str, fl.pr_tion);
		ft_putchar_fd(space, (fl.width - fl.pr_tion));
	}
	else
	{
		ft_putstr_fd(str, fl.len);
		ft_putchar_fd(space, (fl.width - fl.len));
	}
	return (0);
}

static int	pozitiv_str(char *str, t_flags fl, char space)
{
	if (fl.pr_tion >= 0 && fl.pr_tion < fl.len)
	{
		ft_putchar_fd(space, (fl.width - fl.pr_tion));
		ft_putstr_fd(str, fl.pr_tion);
	}
	else
	{
		ft_putchar_fd(space, (fl.width - fl.len));
		ft_putstr_fd(str, fl.len);
	}
	return (0);
}

static int	result(t_flags fl)
{
	int	res;

	res = 0;
	if (fl.width == 0)
	{
		if (fl.pr_tion <= -1)
			res = fl.len;
		else if (fl.pr_tion >= 0)
			res = min(fl.pr_tion, fl.len);
	}
	else if (fl.width > 0)
	{
		if (fl.pr_tion <= -1)
			res = max(fl.width, fl.len);
		else if (fl.pr_tion <= fl.len)
			res = max(fl.width, fl.pr_tion);
		else if (fl.pr_tion > fl.len)
			res = max(fl.width, fl.len);
	}
	return (res);
}

int	ft_printf_s(t_flags fl, char *str)
{
	int		res;
	char	space;

	if (str == NULL)
		str = "(null)";
	fl.len = ft_strlen(str);
	if (fl.len == 0)
	{
		ft_putchar_fd(' ', fl.width);
		return (fl.width);
	}
	res = result(fl);
	space = ' ';
	if (fl.flag == '0')
		space = '0';
	if (fl.flag == '-')
		negativ_str(str, fl, space);
	else
		pozitiv_str(str, fl, space);
	return (res);
}
