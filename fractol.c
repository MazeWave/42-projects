/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:00:28 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 22:24:23 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_frac	frac_init(t_frac *frac)
{
	frac->zoomx = 1;
	frac->zoomy = 1;
	frac->offx = 0.0;
	frac->offy = 0.0;
	frac->mx = 0.0;
	frac->my = 0.0;
	return (*frac);
}

static int	key_hook(int keycode, t_frac *frac)
{
	if (!keycode)
		return (0);
	frac->zoomx += 0.05;
	printf("Hello from key_hook!\n");
	return (0);
}

static int	mouse_hook(int keycode, t_frac *frac)
{
	if (keycode == 4)
	{
		printf("Scroll Up\n");
		frac->zoomx += 0.5;
		frac->zoomy += 0.5;
	}
	else if (keycode == 5)
	{
		printf("Scroll Down\n");
		frac->zoomx -= 0.5;
		frac->zoomy -= 0.5;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*img;
	void	*mlx;
	void	*mlx_win;
	t_frac	fractolstruct;
	t_frac	*frac;

	frac = &fractolstruct;
	frac_init(frac);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol by ldalmass");
	mlx_key_hook(mlx_win, key_hook, frac);
	mlx_mouse_hook(mlx_win, mouse_hook, frac);
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	pre_processor(img, frac, argv, argc);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}
