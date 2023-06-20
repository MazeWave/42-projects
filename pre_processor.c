/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:14:44 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 16:46:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pre_processor(t_data *img, t_frac *frac, char **argv, int argc)
{
	if (argc <= 1 || argc >= 5 || argc == 3)
	{
		usage();
		return (0);
	}
	else if (argv[1][0] == 'm' && argc == 2)
		scanline(*img, 'm', frac);
	else if (argv[1][0] == 'j' && argc == 4)
	{
		frac->jx = ft_atod(argv[2]);
		frac->jy = ft_atod(argv[3]);
		scanline(*img, 'j', frac);
	}
	else
		usage();
	return (0);
}
