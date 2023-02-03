/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:28:14 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 01:47:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

static void		mandelbrot_equation(t_complex *z, t_complex *c);
static void		mandelbrot_der_equation(t_complex *dz, \
										t_complex *z, t_complex dc);
static double	color(double z_mag_sq);
static double	distance(double z_mag_sq, t_complex dz);

t_iteration	distance_estimation(double pixel_size, \
					t_complex *z, \
					t_complex *c)
{
	double		mag_sq;
	t_complex	dz;
	t_complex	dc;
	t_iteration	iteration;

	iteration.iteration = 0;
	set_complex(z, c->real, c->imag);
	set_complex(&dc, (1 * pixel_size * THICKNESS), 0);
	set_complex(&dz, dc.real, dc.imag);
	while (iteration.iteration < MAX_DEPTH)
	{
		mag_sq = mag_squared(z->real, z->imag);
		if (mag_sq < mag_squared(dz.real, dz.imag))
			return ((t_iteration){iteration.iteration, BOUNDARY, 0.});
		if (mag_sq > RADIUS * RADIUS)
			return ((t_iteration){iteration.iteration, \
							OUTSIDE, distance(mag_sq, dz)});
		mandelbrot_der_equation(&dz, z, dc);
		mandelbrot_equation(z, c);
		iteration.iteration++;
	}
	return ((t_iteration){iteration.iteration, INSET, 0.});
}


static double	color(double z_mag_sq)
{
	return (log(log(z_mag_sq)) / log(2));
}

static double	distance(double z_mag_sq, t_complex dz)
{
	return (log(z_mag_sq) * \
		sqrt(z_mag_sq) / mag_squared(dz.real, dz.imag));
}

static void	mandelbrot_equation(t_complex *z, t_complex *c)
{
	multiply(z, z->real, z->imag);
	add(z, c->real, c->imag);
}

static void	mandelbrot_der_equation(t_complex *dz, t_complex *z, t_complex dc)
{
	multiply(dz, z->real, z->imag);
	multiply(dz, 2, 0);
	add(dz, dc.real, dc.imag);
}
