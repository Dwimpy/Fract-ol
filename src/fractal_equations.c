/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:41:11 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 22:09:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"
#include "../include/fractals.h"
#include <math.h>
/*
double	distance(double z_mag_sq, t_complex dz, double power)
{
	double	distance;
	double	k;

	distance = log(z_mag_sq) * 0.5f * \
		sqrt(z_mag_sq / mag_squared(dz.real, dz.imag));
	k = fabs(sin(3.1415)) * 3.f;
	k = (1./sqrt(distance)) * (k * k + .25f);
	return (log(log(z_mag_sq) / power)) / k;
}
*/

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

void	initialize_values(t_complex *dc, \
					t_complex *dz, double pixel_size)
{
	set_complex(dc, (1 * pixel_size * THICKNESS), 0);
	set_complex(dz, dc->real, dc->imag);
}

void	init_map_period(t_pixel_data *pixel_map, t_complex *saved_z, int *check)
{
	pixel_map->iteration.iteration = 0;
	pixel_map->iteration.zone = INSET;
	set_complex(saved_z, 0, 0);
	*check = 0;
}

int	bulb_checking(t_pixel_data *data, t_complex c)
{
	double	q;

	q = (c.real - 0.25) * (c.real - 0.25) + c.imag * c.imag;
	if (q * (q + (c.real - 0.25)) < 0.25 * c.imag * c.imag)
	{
		data->iteration.zone = INSET;
		return (1);
	}
	return (0);
}
