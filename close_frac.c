/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_frac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:08:22 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 21:08:06 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*

Pour checker les leaks ajouter :
	system("leaks fractol");
avant exit

*/

int	close_frac(t_frac *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	free(frac->img.img);
	exit(EXIT_SUCCESS);
}
