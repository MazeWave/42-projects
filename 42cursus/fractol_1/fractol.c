/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:00:28 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 15:36:59 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	mandelbrot(int x, int y, double zx, double zy)
{
	int		n;
	double	sx;
	double	sy;
	double	tx;

	n = 0;
	tx = 0.0;
	sx = (double)x / (WIDTH / 3.0) - 1.5;
	sy = (double)y / (HEIGHT / 3.0) - 0.5;
	while (((zx * zx) + (zy * zy)) <= 4 && n < ITERATION)
	{
		tx = (zx * zx) - (zy * zy) + sx;
		zy = (2.0 * zx * zy) + sy;
		zx = tx;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n);
}

double	julia(int x, int y, double cx, double cy)
{
	int		n;
	double	nx;
	double	ny;
	double	ox;
	double	oy;

	ox = 0;
	oy = 0;
	nx = 1.5 * (x - WIDTH / 2) / (0.75 * 1 * WIDTH) + 0;
	ny = (y - HEIGHT / 2) / (0.5 * 1 * HEIGHT) + 0;
	n = 0;
	while (n < ITERATION)
	{
		ox = nx;
		oy = ny;
		nx = (ox * ox) - (oy * oy) + cx;
		ny = (2 * ox * oy) + cy;
		if (((nx * nx) + (ny * ny)) > 4)
			break ;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n);
}

static void	scanline(t_data img, char argv)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < WIDTH)
	{
		while (++y < HEIGHT)
		{
			if (argv == 'm')
				my_mlx_pixel_put(&img, x, y,
					ft_huetorgb(mandelbrot(x, y, 0.0, 0.0), 0, 0, 0));
			else
				my_mlx_pixel_put(&img, x, y,
					ft_huetorgb(julia(x, y, -0.7, 0.27015), 0, 0, 0));
		}
		y = -1;
	}
	return ;
}

int	pre_processor(t_data *img, char **argv)
{
	if (argv[1][0] == 'm')
		scanline(*img, 'm');
	else if (argv[1][0] == 'j')
		scanline(*img, 'j');
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*img;
	void	*mlx;
	void	*mlx_win;
	int		i;

	if (argc != 2)
		return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol by ldalmass");
	i = -1;
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	pre_processor(img, argv);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}
