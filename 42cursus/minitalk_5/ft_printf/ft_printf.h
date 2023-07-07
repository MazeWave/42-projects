/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:21:56 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/05 20:18:44 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_printerchar(char c, int len);
int		ft_printerstr(char *s, int len);
int		ft_printernbr_hexa(unsigned int n, int i, int len);
int		ft_printernbr_unsigned(unsigned int n, int len);
int		ft_adress_hexa(unsigned long args, int len);
int		ft_count_numbers(int n, int len);
int		ft_printernbr(int n, int len);
char	*ft_stringchr(const char *s, int c);

#endif
