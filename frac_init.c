/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:44:22 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 19:04:45 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac	frac_init(t_frac *frac, void *mlx, void *mlx_win, t_data img)
{
	frac->zoomx = 1;
	frac->zoomy = 1;
	frac->offx = 0.0;
	frac->offy = 0.0;
	frac->mx = 0.0;
	frac->my = 0.0;
	frac->color = 360 * 360 * 360;
	frac->mlx = mlx;
	frac->win = mlx_win;
	frac->img = img;
	return (*frac);
}
