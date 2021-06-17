#include "ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_putnbr_fd(long long c, int fd)
{
	char	i;

	if (c == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (c < 0)
	{
		write(fd, "-", 1);
		c *= -1;
	}
	if (c > 9)
		ft_putnbr_fd(c / 10, fd);
	i = (c % 10) + '0';
	if (ft_isdigit(i) == 1)
		write(fd, &i, 1);
}

static int	get_x_chr(unsigned long num, t_flags fl)
{
	if (num >= 0 && num <= 9)
		return (num + '0');
	num %= 10;
	if (fl.type == 'X')
		return (num + 'A');
	else
		return (num + 'a');
}

void	ft_putnbr_xfd(unsigned long c, t_flags fl)
{
	char	i;

	if (c >= 16)
		ft_putnbr_xfd(c / 16, fl);
	i = get_x_chr(c % 16, fl);
	ft_putchar_fd(i, 1);
}

int	ft_putnbr_x(unsigned long c, int baze)
{
	int	i;

	i = 0;
	if (c == 0)
		i++;
	while (c > 0)
	{
		c /= baze;
		i++;
	}
	return (i);
}
