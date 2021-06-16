#include "ft_printf.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	while (c[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *c, int fd)
{
	int	i;

	i = 0;
	if (!c || fd < 0)
		return ;
	while (i < fd)
	{
		write(1, &c[i], 1);
		i++;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
