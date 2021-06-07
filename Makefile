NAME	= libftprintf.a
HEADER	= ft_printf.h

LIST		= lib_func_0.c lib_func_1.c parser.c ft_printf.c ft_printf_di.c type_handling.c

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

.o:.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME) :	$(OBJ)
			ar rc $(NAME) $(OBJ)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
