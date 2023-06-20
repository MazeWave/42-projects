# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 18:55:24 by ldalmass          #+#    #+#              #
#    Updated: 2023/06/20 20:17:50 by ldalmass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL			=	fractol.c \
					julia.c \
					mandelbrot.c \
					my_mlx_pixel_put.c \
					ft_huetorgb.c \
					ft_encode_trgb.c \
					scanline.c \
					pre_processor.c \
					usage.c \
					frac_init.c \
					key_hook.c \
					mouse_hook.c \
					close_frac.c \

OBJS_FRACTOL	=	$(FRACTOL:.c=.o)

CC				=	cc

PRINTF			=	./src/ft_printf/ft_printf.a

LIBFT			=	./src/libft/libft.a

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -rf

NAME_FRACTOL	=	fractol

#rules
all : $(NAME_FRACTOL)

$(NAME_FRACTOL) : $(LIBFT) $(PRINTF) $(OBJS_FRACTOL)
	$(CC) $(OBJS_FRACTOL) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME_FRACTOL)
	$(RM) $(NAME_FRACTOL).o

$(LIBFT) :
	make -C ./src/libft

$(PRINTF) :
	make -C ./src/ft_printf

clean :
	$(RM) $(OBJS_FRACTOL)
	make clean -C ./src/libft
	make clean -C ./src/ft_printf

fclean : clean
	$(RM) $(NAME_FRACTOL)
	$(RM) $(UTILS) $(LIBFT) $(PRINTF)

re : fclean all
