#include "ft_printf.h"

int	ft_putnbr(int c, int baze)
{
	int	i;

	i = 0;
	if (c < 0)
		c *= -1;
	if (c == 0)
		i++;
	while (c > 0)
	{
		ft_putnbr(c / baze, baze);
		c /= baze;
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

t_flags	zero_flags(void)
{
	t_flags fl;

	fl.flag = ' ';
	fl.width = 0;
	fl.pr_tion = -1;
	fl.type = 0;
	return (fl);
}

