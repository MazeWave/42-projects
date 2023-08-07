/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:12:34 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 03:55:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_truncate(char *str)
{
	char	*result;
	int		result_len;
	int		neg;

	neg = 0;
	if (str == NULL)
		return (NULL);
	if (str[0] == '-')
	{
		str++;
		neg++;
	}
	if (str[0] == '+')
		str++;
	while (*str == '0')
		str++;
	result_len = ft_strlen(str) + 1 + neg;
	result = malloc(sizeof(char) * result_len);
	if (result == NULL)
		return (NULL);
	if (neg == 1)
		result[0] = '-';
	ft_strlcpy(result + neg, str, result_len);
	return (result);
}

int	check_limits(t_ps *ps)
{
	int		i;
	int		error;
	char	*arg;

	i = 1;
	error = 0;
	while (i <= (ps->argc - 1))
	{
		arg = ft_truncate(ps->argv[i]);
		if (arg[0] == '-')
		{
			if ((ft_strlen(arg) == 11 
					&& ft_strncmp(arg, "-2147483648", ft_strlen(arg)) > 0)
				|| ft_strlen(arg) > 11)
				error++;
		}
		else if ((ft_strlen(arg) == 10 
				&& ft_strncmp(arg, "2147483647", ft_strlen(arg)) > 0) 
			|| ft_strlen(arg) > 10)
			error++;
		i++;
		free(arg);
	}
	return (error);
}
