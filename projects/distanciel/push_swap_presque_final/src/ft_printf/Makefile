SRCS 	= ft_printf.c \
		  ft_printerchar.c \
		  ft_printerstr.c \
		  ft_printernbr.c \
		  ft_printertnbr_unsigned.c \
		  ft_printernbr_hexa.c \
		  ft_adress_hexa.c \
		  ft_stringchr.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -rf

NAME	= ft_printf.a

#rules
%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "$<                             \r"

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all $(NAME) clean fclean re
