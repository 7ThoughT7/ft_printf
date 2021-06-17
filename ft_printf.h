#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_flags_arg
{
	char	flag;
	int		width;
	int		pr_tion;
	int		type;
	int		len;
}		t_flags;

int		ft_printf(const char *str, ...);
int		ft_putnbr(long long c, int baze);
int		ft_putnbr_x(unsigned long c, int baze);
void	ft_putnbr_fd(long long c, int fd);
void	ft_putnbr_xfd(unsigned long c, t_flags fl);
int		ft_isdigit(int c);
int		max(int a, int b);
int		min(int a, int b);
int		ft_strlen(char *c);
void	ft_putchar_fd(char c, int n);
void	ft_putstr_fd(const char *c, int fd);
char	*ft_strchr(const char *s, int c);
t_flags	zero_flags(void);
int		parser(const char *str, t_flags *fl, va_list ap);
int		ft_printf_di(t_flags fl, int num);
int		ft_printf_x(t_flags fl, unsigned int num);
int		ft_printf_s(t_flags fl, char *str);
int		ft_printf_u(t_flags fl, unsigned int num);
int		ft_printf_p(t_flags fl, unsigned long num);
int		ft_printf_c(t_flags fl, char c);
int		type_handling(t_flags fl, va_list ap);

#endif