/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:21:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 21:58:06 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_printf("Usage:			./fractol [fractal] (options)\n");
	ft_printf("Exemple:		./fractol m\n\n");
	ft_printf("Fractals: mandelbrot as m, julia as j\n");
	ft_printf("Beaucoup de set de Julia vont mal rendre,");
	ft_printf(" attention aux valeurs entrées !\n");
	ft_printf("Utilisez les valeurs ci dessous pour tester.\n\n");
	ft_printf("Exemple:		./fractol j -0.7 0.27015\n");
	ft_printf("Exemple:		./fractol j -0.4 0.579\n");
	exit(0);
}
