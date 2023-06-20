/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huetorgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:14:34 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 20:17:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_huetorgb(int hue, double r, double g, double b)
{
	double	h;
	double	c;
	double	x;

	if (hue == -1)
		return (0x00000000);
	h = (hue % 360) / 60.0;
	c = 1.0;
	x = c * (1.0 - fabs(fmod(h, 2) - 1.0));
	if ((h >= 1 && h < 2) || (h >= 4 && h < 5))
		r = x;
	else if ((h >= 0 && h < 1) || (h >= 5 && h < 6))
		r = c;
	if ((h >= 3 && h < 4) || (h >= 0 && h < 1))
		g = x;
	else if ((h >= 1 && h < 2) || (h >= 2 && h < 3))
		g = c;
	if ((h >= 5 && h < 6) || (h >= 2 && h < 3))
		b = x;
	else if ((h >= 3 && h < 4) || (h >= 4 && h < 5))
		b = c;
	hue = 0 << 24 | (int)(r * 255) << 16 | (int)(g * 255) << 8 | (int)(b * 255);
	return (hue);
}
