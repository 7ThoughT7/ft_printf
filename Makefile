NAME	= libftprintf.a
HEADER	= ft_printf.h

LIST		= lib_func_0.c lib_func_1.c lib_func_2.c ft_printf_u.c ft_printf.c ft_printf_di.c ft_printf_s.c \
				ft_printf_x.c type_handling.c ft_printf_p.c ft_printf_c.c parser.c

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

.o:.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			ar -rcs $(NAME) *.o $(OBJ)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
