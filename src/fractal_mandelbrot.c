/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:28:14 by arobu             #+#    #+#             */
/*   Updated: 2023/01/28 05:28:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

void	mandelbrot_equation(t_complex *z, t_complex *c);
void	mandelbrot_der_equation(t_complex *dz, t_complex *z, t_complex dc);

t_iteration	distance_estimation(double pixel_size, \
									t_complex *z, \
										t_complex *c)
{
	double		mag_square;
	t_complex	dz;
	t_complex	dc;
	t_iteration	iteration;

	iteration.iteration = 0;
	set_complex(z, c->real, c->imag);
	set_complex(&dc, (1 * pixel_size * THICKNESS), 0);
	set_complex(&dz, dc.real, dc.imag);
	while (iteration.iteration < MAX_DEPTH)
	{		
		mag_square = mag_squared(z->real, z->imag);
		if (mag_square < mag_squared(dz.real, dz.imag))
			return ((t_iteration){.iteration = iteration.iteration, \
									iteration.zone = BOUNDARY});
		if (mag_square > RADIUS)
			return ((t_iteration){.iteration = iteration.iteration, \
									iteration.zone = OUTSIDE});
		mandelbrot_der_equation(&dz, z, dc);
		mandelbrot_equation(z, c);
		iteration.iteration++;
	}
	return ((t_iteration){.zone = INSET});
}

void	mandelbrot_equation(t_complex *z, t_complex *c)
{
	multiply(z, z->real, z->imag);
	add(z, c->real, c->imag);
}

void	mandelbrot_der_equation(t_complex *dz, t_complex *z, t_complex dc)
{
	multiply(dz, z->real, z->imag);
	multiply(dz, 2, 0);
	add(dz, dc.real, dc.imag);
}