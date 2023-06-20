/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:48:41 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 20:38:36 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, t_frac *frac)
{
	if (keycode == 15)
	{
		frac->zoomx += 5;
		frac->zoomy += 5;
	}
	if (keycode == 17)
	{
		frac->zoomx += 50;
		frac->zoomy += 50;
	}
	if (keycode == 3)
	{
		frac->zoomx -= 5;
		frac->zoomy -= 5;
	}
	if (keycode == 5)
	{
		frac->zoomx -= 50;
		frac->zoomy -= 50;
	}
	scanline(frac->img, frac->argv[1][0], frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img.img, 0, 0);
	return (0);
}
