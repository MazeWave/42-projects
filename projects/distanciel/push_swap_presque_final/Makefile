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

PUSH_SWAP				=	push_swap.c \
							usage.c \
							check_types.c \
							create_stacks_for_doublon.c \
							check_doublon.c \
							create_stacks.c \
							close_swap.c \
							print_stack.c \
							check_limits.c \
							parser.c \
							stack_len.c \
							sa.c \
							sb.c \
							ss.c \
							pa.c \
							pb.c \
							ra.c \
							rb.c \
							rr.c \
							rra.c \
							rrb.c \
							rrr.c \
							choose_sort.c \
							push_min.c \
							create_index.c \

OBJS_PUSH_SWAP			=	$(PUSH_SWAP:.c=.o)

CC						=	cc

PRINTF					=	./src/ft_printf/ft_printf.a

LIBFT					=	./src/libft/libft.a

CFLAGS					=	-Wall -Werror -Wextra

RM						=	rm -rf

NAME_PUSH_SWAP			=	push_swap

#rules
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
all : $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP) : $(LIBFT) $(PRINTF) $(OBJS_PUSH_SWAP)
	@$(CC) $(OBJS_PUSH_SWAP) $(LIBFT) $(PRINTF) -o $(NAME_PUSH_SWAP)
	@$(RM) $(NAME_PUSH_SWAP).o

$(LIBFT) :
	@make -C ./src/libft

$(PRINTF) :
	@make -C ./src/ft_printf

clean :
	@$(RM) $(OBJS_PUSH_SWAP)
	@make clean -C ./src/libft
	@make clean -C ./src/ft_printf

fclean : clean
	@$(RM) $(NAME_PUSH_SWAP)
	@$(RM) $(LIBFT) $(PRINTF)

re : fclean all
