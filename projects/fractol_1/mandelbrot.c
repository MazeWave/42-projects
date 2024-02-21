/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:35:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/05/24 00:26:34 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mandelbrot(int x, int y)
{
	int		n;
	double	zx;
	double	zy;
	double	sx;
	double	sy;

	n = 0;
	zx = 0;
	zy = 0;
	sx = (double)x / 1000.0 - 2.0;
	sy = (double)x / 1000.0 - 1.12;
	while (((zx * zx) + (zy * zy)) <= 4 && n < ITERATION)
	{
		zx = zx * zx - zy * zy + sx;
		zy = 2.0 * zx * zy + sy;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n);
}
