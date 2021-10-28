CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_printf.c ft_lib.c ft_type_print.c ft_itoas.c
			

OBJ			= $(SRC:.c=.o)

LIB			= libftprintf.a

all:		$(LIB)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(LIB):		$(OBJ)
			ar rc $(LIB) $(OBJ)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(LIB)

re:			fclean all

.PHONY:		re clean fclean all
