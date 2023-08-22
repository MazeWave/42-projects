# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 18:55:24 by ldalmass          #+#    #+#              #
#    Updated: 2023/07/15 03:44:31 by ldalmass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO				=	philo.c \
						print_struct.c \
						usage.c \
						parser.c \
						parse_argv.c \
						ft_atoi.c \
						init_struct.c \
						check_input_value.c \
						routine.c \
						create_threads.c \
						join_threads.c \


OBJS_PHILO			=	$(PHILO:.c=.o)

CC					=	cc

CFLAGS				=	-Wall -Werror -Wextra

RM					=	rm -rf

NAME_PHILO			=	philo

#rules
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME_PHILO)

$(NAME_PHILO) : $(OBJS_PHILO)
	@$(CC) $(OBJS_PHILO) -o $(NAME_PHILO)
	@$(RM) $(NAME_PHILO).o

clean :
	@$(RM) $(OBJS_PHILO)

fclean : clean
	@$(RM) $(NAME_PHILO)

re : fclean all
