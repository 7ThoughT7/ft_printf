#include "ft_printf.h"

int	parser(const char *str, t_flags *fl, va_list ap)
{
	int count;
	char *type;
	int res;
	int	num;

	res = 0;
	count = 0;
	type = "cspdiuxX%";
	while (str[count] != '\0')
	{
		if (str[count] == '%' && str[count + 1] != '\0' &&
			str[count + 1] != '%')
		{
			*fl = zero_flags();
			count++;
			while (str[count] == '0' || str[count] == '-')
			{
				if (str[count] == '0')
					fl->zero = 1;
				if (str[count] == '-')
				{
					fl->minus = 1;
					fl->zero = 0;
				}
				count++;
			}
			while (ft_isdigit(str[count]) || str[count] == '*')
			{
				if (ft_isdigit(str[count]))
					fl->width = fl->width * 10 + (str[count] - '0');
				if (str[count] == '*')
					fl->width = va_arg(ap, int);
				count++;
			}
			if (str[count] == '.')
				count++;
			while (ft_isdigit(str[count]) || str[count] == '*')
			{
				if (ft_isdigit(str[count]))
					fl->pr_tion = fl->pr_tion * 10 + (str[count] - '0');
				if (str[count] == '*')
					fl->pr_tion = va_arg(ap, int);
				count++;
			}
			while (ft_strchr(type, str[count]))
			{
				fl->type = (int)str[count];
				count++;
			}
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