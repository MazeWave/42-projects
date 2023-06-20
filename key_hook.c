/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:47:02 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 21:06:45 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Quitter (la croix rouge marche aussi)
53 = Echap

Déplacement
126 / 13 = Flèche Haut / W
125 / 1 = Flèche Bas / S
124 / 2 = Flèche Droite / D
123 / 0 = Flèche Gauche / A

Changement de couleurs
12 = E
14 = Q

Zoom
15 = R
5 = F
17 = T
3 = G
*/

int	key_hook(int keycode, t_frac *frac)
{
	if (!keycode)
		return (0);
	if (keycode == 53)
		close_frac(frac);
	if (keycode == 126 || keycode == 13)
		frac->offy -= 0.05;
	if (keycode == 125 || keycode == 1)
		frac->offy += 0.05;
	if (keycode == 124 || keycode == 2)
		frac->offx += 0.05;
	if (keycode == 123 || keycode == 0)
		frac->offx -= 0.05;
	if (keycode == 12)
		frac->color += 5;
	if (keycode == 14)
		frac->color -= 5;
	if (keycode == 15 || keycode == 17 || keycode == 5 || keycode == 3)
		mouse_hook(keycode, frac);
	scanline(frac->img, frac->argv[1][0], frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img.img, 0, 0);
	return (0);
}
