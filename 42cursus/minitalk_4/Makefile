# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 19:22:52 by ldalmass          #+#    #+#              #
#    Updated: 2023/04/11 21:16:35 by ldalmass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 			= server.c 

CLIENT			= client.c

SERVER_B		= server_bonus.c

CLIENT_B		= client_bonus.c

OBJS_SERVER		= $(SERVER:.c=.o)

OBJS_CLIENT		= $(CLIENT:.c=.o)

OBJS_SERVER_B	= $(SERVER_B:.c=.o)

OBJS_CLIENT_B	= $(CLIENT_B:.c=.o)

CC				= gcc

PRINTF			= ft_printf/ft_printf.a

LIB				= libft/libft.a

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf

NAME_CLIENT		= client

NAME_SERVER		= server

NAME_CLIENT_B	= client_bonus

NAME_SERVER_B	= server_bonus

#rules
all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(LIB) $(PRINTF) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(LIB) $(PRINTF) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(LIB) $(PRINTF) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(LIB) $(PRINTF) $(OBJS_SERVER) -o $(NAME_SERVER)

$(LIB) :
	make -C libft

$(PRINTF) :
	make -C ft_printf

bonus : $(NAME_CLIENT_B) $(NAME_SERVER_B)

$(NAME_CLIENT_B) : $(LIB) $(PRINTF) $(OBJS_CLIENT_B)
	$(CC) $(CFLAGS) $(LIB) $(PRINTF) $(OBJS_CLIENT_B) -o $(NAME_CLIENT_B)

$(NAME_SERVER_B) : $(LIB) $(PRINTF) $(OBJS_SERVER_B)
	$(CC) $(CFLAGS) $(LIB) $(PRINTF) $(OBJS_SERVER_B) -o $(NAME_SERVER_B)

clean :
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_B) $(OBJS_SERVER_B)
	make clean -C libft
	make clean -C ft_printf

fclean : clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_B) $(NAME_SERVER_B)
	$(RM) $(LIB) $(PRINTF)

re : fclean all
