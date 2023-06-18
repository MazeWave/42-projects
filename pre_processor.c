/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:14:44 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 22:15:31 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pre_processor(t_data *img, t_frac *frac, char **argv, int argc)
{
	if (argc < 2)
	{
		usage();
		return (0);
	}
	/*frac->zoomx = 1;
	frac->zoomy = 1;
	frac->offx = 0.0;
	frac->offy = 0.0;
	frac->mx = 0.0;
	frac->my = 0.0;*/
	if (argv[1][0] == 'm')
		scanline(*img, 'm', frac);
	else if (argv[1][0] == 'j')
	{
		frac->jx = ft_atod(argv[2]);
		frac->jy = ft_atod(argv[3]);
		scanline(*img, 'j', frac);
	}
	else if (argv[1][0] != 'm' && argv[1][0] != 'j')
		usage();
	return (0);
}
