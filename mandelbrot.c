/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:35:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 20:34:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int x, int y, t_frac *frac)
{
	int		n;
	double	sx;
	double	sy;
	double	tx;

	frac->mx = 0.0;
	frac->my = 0.0;
	n = 0;
	tx = 0.0;
	sx = 1.5 * (x - WIDTH / 2) / (0.75 * frac->zoomx * WIDTH) + frac->offx;
	sy = (y - HEIGHT / 2) / (0.5 * frac->zoomy * HEIGHT) + frac->offy;
	while ((frac->mx * frac->mx) + (frac->my * frac->my) <= 4 && n < ITERATION)
	{
		tx = (frac->mx * frac->mx) - (frac->my * frac->my) + sx;
		frac->my = (2.0 * frac->mx * frac->my) + sy;
		frac->mx = tx;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n + (ITERATION));
}
