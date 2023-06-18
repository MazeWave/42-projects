/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:13:55 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 21:33:12 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scanline(t_data img, char argv, t_frac *frac)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < WIDTH)
	{
		while (++y < HEIGHT)
		{
			if (argv == 'm')
				my_mlx_pixel_put(&img, x, y,
					ft_huetorgb(mandelbrot(x, y, frac), 0, 0, 0));
			else
				my_mlx_pixel_put(&img, x, y,
					ft_huetorgb(julia(x, y, frac), 0, 0, 0));
		}
		y = -1;
	}
	return ;
}
