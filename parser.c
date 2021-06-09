#include "ft_printf.h"

int	fl_flag(t_flags *fl, const char *str, int count)
{
	if (str[count] == '0')
	{
		if (fl->flag == '-')
		{
			count++;
			return (count);
		}
		fl->flag = '0';
		count++;
	}
	if (str[count] == '-')
	{
		fl->flag = '-';
		count++;
	}
	return (count);
}

int	fl_width(t_flags *fl, const char *str, int count, va_list ap)
{
	int num;

	if (ft_isdigit(str[count]))
		fl->width = fl->width * 10 + (str[count] - '0');
	if (str[count] == '*')
	{
		num = va_arg(ap, int);
		if (num < 0)
		{
			fl->flag = '-';
			num *= -1;
			fl->width = num;
		}
		else
			fl->width = num;
	}
	count++;
	return (count);
}

int	fl_pr_tion(t_flags *fl, const char *str, int count, va_list ap)
{
	if (ft_isdigit(str[count]))
		fl->pr_tion = fl->pr_tion * 10 + (str[count] - '0');
	if (str[count] == '*')
		fl->pr_tion = va_arg(ap, int);
	count++;
	return (count);
}

int	modifiers(t_flags *fl, const char *str, int count, va_list ap)
{
	char *type;

	type = "cspdiuxX%";
	*fl = zero_flags();
	count++;
	while (str[count] == '0' || str[count] == '-')
		count = fl_flag(fl, str, count);
	while (ft_isdigit(str[count]) || str[count] == '*')
		count = fl_width(fl, str, count, ap);
	if (str[count] == '.')
	{
		count++;
		fl->pr_tion = 0;
		while (ft_isdigit(str[count]) || str[count] == '*')
			count = fl_pr_tion(fl, str, count, ap);
	}
	while (ft_strchr(type, str[count]))
	{
		fl->type = (int)str[count];
		count++;
	}
	return (count);
}

int	parser(const char *str, t_flags *fl, va_list ap)
{
	int count;
	int res;
	int	num;

	res = 0;
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '%' && str[count + 1] != '\0' &&
			str[count + 1] != '%')
		{
			count = modifiers(fl, str, count, ap);
			num = va_arg(ap, int);
			res += type_handling(*fl, num);
		}
		else
		{
			ft_putchar_fd(str[count], 1);
			count++;
			res++;
		}
	}
	return (res);
}