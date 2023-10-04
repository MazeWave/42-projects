/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:15:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/09/24 18:12:18 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	limit_check(t_rules *data)
{
	char	*arg;
	int		error;
	int		i;

	error = 0;
	i = 0;
	while (++i < data->argc)
	{
		arg = ft_truncate(data->argv[i]);
		if ((ft_strlen(arg) == 10
				&& ft_strncmp(arg, "2147483647", ft_strlen(arg)) > 0)
			|| ft_strlen(arg) > 10)
			error++;
		free(arg);
	}
	return (error);
}

static int	char_check(t_rules *data)
{
	int	error;
	int	i;
	int	j;

	error = 0;
	i = 0;
	j = 0;
	while (++i < data->argc)
	{
		while (data->argv[i][j] != '\0')
		{
			if (data->argv[i][j] < '0' || data->argv[i][j] > '9')
				error++;
			j++;
		}
		j = 0;
	}
	return (error);
}

int	parser(t_rules *data)
{
	int	error;

	error = 0;
	if (data->argc > 6 || data->argc < 5)
		return (++error);
	error += char_check(data);
	error += limit_check(data);
	return (error);
}
