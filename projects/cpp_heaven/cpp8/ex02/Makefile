# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:57:18 by ldalmass          #+#    #+#              #
#    Updated: 2024/11/30 17:27:10 by ldalmass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER	= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= MutantStack
SRCS		=	main.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -rf

%.o 		:	%.cpp
	@$(COMPILER) $(FLAGS) -c $< -o $@

all			: $(NAME)
$(NAME)		: $(OBJS)
	@$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "✅		Compilation done"

clean		:
	@$(RM) $(OBJS)
	@echo "✅🧹🧹		clean done"

fclean		: clean
	@$(RM) $(NAME)
	@echo "✅🧹🧹		fclean done"

re			: fclean all
	@echo "✅🔄️		recompiled successfully"