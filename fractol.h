/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 22:11:16 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>

# include <stdio.h>
# include <stdlib.h>

# include <mlx.h>
# include <math.h>

# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"

# define WIDTH 1024
# define HEIGHT 1024
# define ITERATION 360

typedef struct s_frac
{
	double	zoomx;
	double	zoomy;
	double	offx;
	double	offy;
	double	mx;
	double	my;
	double	jx;
	double	jy;
	double	zero;
}	t_frac;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

int		pre_processor(t_data *img, t_frac *frac, char **argv, int argc);
//int		pre_processor(t_data *img, char **argv, t_frac *frac, int argc);
void	scanline(t_data img, char argv, t_frac *frac);
int		ft_huetorgb(int hue, double r, double g, double b);
int		ft_encode_trgb(int t, int r, int g, int b);
int		mandelbrot(int x, int y, t_frac *frac);
double	julia(int x, int y, t_frac *frac);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	usage(void);

#endif