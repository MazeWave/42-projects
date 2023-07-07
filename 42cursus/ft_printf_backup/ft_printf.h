
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

int	ft_putchar(va_list c, int len);
int	ft_putstr(char *s, int len);
int	ft_putnbr(int n, int len);
int	ft_putnbr_hexa(unsigned int n, int i, int len);
int	ft_putnbr_unsigned(unsigned int n, int len);
int	ft_adress_hexa(va_list args, int len);

#endif
