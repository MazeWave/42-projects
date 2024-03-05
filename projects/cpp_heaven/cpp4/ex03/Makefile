# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:57:18 by ldalmass          #+#    #+#              #
#    Updated: 2024/03/05 15:20:02 by ldalmass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER	= g++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= Animal
SRCS		=	main.cpp\
				AMateria.cpp\
				ICharacter.cpp\
				IMateriaSource.cpp\
				MateriaSource.cpp\
				Character.cpp\
				Cure.cpp\
				Ice.cpp
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