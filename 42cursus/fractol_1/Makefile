# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 18:55:24 by ldalmass          #+#    #+#              #
#    Updated: 2023/06/16 16:16:23 by ldalmass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL			= fractol.c

OBJS_FRACTOL	= $(FRACTOL:.c=.o)

CC				= cc

UTILS			= ./src/utils/utils.a

PRINTF			= ./src/ft_printf/ft_printf.a

LIBFT			= ./src/libft/libft.a

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf

NAME_FRACTOL	= fractol

#rules
all : $(NAME_FRACTOL)

$(NAME_FRACTOL) : $(UTILS) $(LIBFT) $(PRINTF) $(OBJS_FRACTOL)
	$(CC) $(OBJS_FRACTOL) $(LIBFT) $(PRINTF) $(UTILS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_FRACTOL)
	$(RM) $(NAME_FRACTOL).o

$(UTILS) :
	make -C ./src/utils

$(LIBFT) :
	make -C ./src/libft

$(PRINTF) :
	make -C ./src/ft_printf

clean :
	$(RM) $(OBJS_FRACTOL)
	make clean -C ./src/utils
	make clean -C ./src/libft
	make clean -C ./src/ft_printf

fclean : clean
	$(RM) $(NAME_FRACTOL)
	$(RM) $(UTILS) $(LIBFT) $(PRINTF)

re : fclean all
