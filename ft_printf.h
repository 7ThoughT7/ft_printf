#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct flags_arg
{
	char	flag;
	int		width;
	int		pr_tion;
	int		type;
	int		len;
}		t_flags;

//int		ft_isalpha(int c);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int c, int baze);
int		ft_isdigit(int c);
int		max(int a, int b);
void	ft_putchar_fd(char c, int n);
char	*ft_strchr(const char *s, int c);
t_flags	zero_flags();
int		parser(const char *str, t_flags *fl, va_list ap);
int		ft_printf_di(t_flags fl, int num);
int		ft_printf_x(t_flags fl, int num);
void	ft_putnbr_fd(int c, int fd);
int		type_handling(t_flags fl, int num);


#endif