/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:52:30 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 18:48:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	julia(int x, int y, t_frac *frac)
{
	int		n;
	double	nx;
	double	ny;
	double	ox;
	double	oy;

	ox = 0;
	oy = 0;
	nx = 1.5 * (x - WIDTH / 2) / (0.75 * frac->zoomx * WIDTH) + frac->offx;
	ny = (y - HEIGHT / 2) / (0.5 * frac->zoomy * HEIGHT) + frac->offy;
	n = 0;
	while (n < ITERATION)
	{
		ox = nx;
		oy = ny;
		nx = (ox * ox) - (oy * oy) + frac->jx;
		ny = (2 * ox * oy) + frac->jy;
		if (((nx * nx) + (ny * ny)) > 4)
			break ;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n + frac->color);
}
