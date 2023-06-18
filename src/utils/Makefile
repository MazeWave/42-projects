SRCS 	=	ft_encode_trgb.c \
			ft_huetorgb.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra #-O3

RM		= rm -rf

NAME	= utils.a

#rules

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all $(NAME) clean fclean re
