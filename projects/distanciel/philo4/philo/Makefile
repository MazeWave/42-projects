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
						utils1.c \
						utils2.c \
						utils3.c \
						parser.c \
						actions1.c \
						run_simulation.c \
						routine.c \

OBJS_PHILO			=	$(PHILO:.c=.o)

CC					=	cc

CFLAGS				=	-Wall -Werror -Wextra -g -pthread

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
