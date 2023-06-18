/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huetorgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:14:34 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/17 01:14:26 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
//#include <math.h>
//#include <stdio.h>

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
	r = (h >= 1 && h < 2) || (h >= 4 && h < 5) ? x : ((h >= 0 && h < 1) || (h >= 5 && h < 6) ? c : r);
	g = (h >= 3 && h < 4) || (h >= 0 && h < 1) ? x : ((h >= 1 && h < 2) || (h >= 2 && h < 3) ? c : g);
	b = (h >= 5 && h < 6) || (h >= 2 && h < 3) ? x : ((h >= 3 && h < 4) || (h >= 4 && h < 5) ? c : b);
	hue = 0 << 24 | (int)(r * 255) << 16 | (int)(g * 255) << 8 | (int)(b * 255);
	return (hue);
}

/*int main(void)
{
	int i;

	i = 0;
	while (i <= 360)
	{
		int hue = ft_huetorgb(i, 0, 0, 0);
		printf("Hue: %d -> HEX: (%X)\n", i, hue);
		i++;
	}
	return 0;
}*/
