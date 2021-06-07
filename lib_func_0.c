#include "ft_printf.h"

int	ft_putnbr(int c)
{
	int	i;

	i = 1;
	if (c < 0)
		c *= -1;
	while (c > 9)
	{
		ft_putnbr(c / 10);
		c /= 10;
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
	t_flags flag;

	flag.zero = 0;
	flag.minus = 0;
	flag.width = 0;
	flag.pr_tion = 0;
	flag.type = 0;
	return (flag);
}

