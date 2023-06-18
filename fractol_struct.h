/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/17 01:23:15 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>

# include <stdio.h>
# include <stdlib.h>

# include <mlx.h>
# include <math.h>

# include "src/utils/utils.h"
# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"

# define WIDTH 1024
# define HEIGHT 1024
# define ITERATION 360
# define ZOOM 1.0
# define OFFX 1.5
# define OFFY 2.0

typedef struct s_frac{
	int i;
	int y;

} t_frac

#endif
