/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:00:28 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 20:41:34 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*img;
	void	*mlx;
	void	*mlx_win;
	t_frac	fractolstruct;
	t_frac	*frac;

	frac = &fractolstruct;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol by ldalmass");
	mlx_hook(mlx_win, 17, 1L << 0, close_frac, frac);
	mlx_key_hook(mlx_win, key_hook, frac);
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	frac->argv = argv;
	frac_init(frac, mlx, mlx_win, *img);
	pre_processor(img, frac, argv, argc);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img.img, 0, 0);
	mlx_loop(mlx);
}
