/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/20 21:04:36 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>

# include <math.h>
# include <mlx.h>

# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"

# define WIDTH 256
# define HEIGHT 256
# define ITERATION 200

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_frac
{
	int				color;
	unsigned int	zoomx;
	unsigned int	zoomy;
	double			offx;
	double			offy;
	double			mx;
	double			my;
	double			jx;
	double			jy;
	int				mouse_x;
	int				mouse_y;
	char			**argv;
	void			*mlx;
	void			*win;
	t_data			img;
}	t_frac;

t_frac	frac_init(t_frac *frac, void *mlx, void *mlx_win, t_data img);
int		key_hook(int keycode, t_frac *frac);
int		mouse_hook(int keycode, t_frac *frac);
int		pre_processor(t_data *img, t_frac *frac, char **argv, int argc);
void	scanline(t_data img, char argv, t_frac *frac);
int		ft_huetorgb(int hue, double r, double g, double b);
int		ft_encode_trgb(int t, int r, int g, int b);
int		mandelbrot(int x, int y, t_frac *frac);
double	julia(int x, int y, t_frac *frac);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	usage(void);
int		close_frac(t_frac *frac);

#endif