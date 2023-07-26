/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 03:41:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"

typedef struct s_ps
{
	int				argc;
	char			**argv;
	int				index;
	int				value;
	struct s_ps		*next;
}					t_ps;

void	usage(void);
int		check_limits(t_ps *ps);
int		check_types(t_ps *ps);
int		check_doublon(t_ps *ps, int value, int index);
void	create_stacks(t_ps *ps, int i);
void	close_swap(t_ps *ps_a);
void	print_stack(t_ps *ps, char c);
int		parser(t_ps *ps);
int		stack_len(t_ps *ps);
void	sa(t_ps *ps, int p);
void	sb(t_ps *ps, int p);
void	ss(t_ps *ps_a, t_ps *ps_b);
void	pa(t_ps **ps_a, t_ps **ps_b);
void	pb(t_ps **ps_a, t_ps **ps_b);
void	ra(t_ps **ps, int p);
void	rb(t_ps **ps, int p);
void	rr(t_ps **ps_a, t_ps **ps_b);
void	rra(t_ps **ps, int p);
void	rrb(t_ps **ps, int p);
void	rrr(t_ps **ps_a, t_ps **ps_b);
void	choose_sort(t_ps **pa, t_ps **pb);
void	push_min(t_ps **pa, t_ps **pb);
void	push_max(t_ps **pa, t_ps **pb);

#endif