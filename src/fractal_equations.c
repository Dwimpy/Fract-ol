/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:41:11 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 01:48:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"
#include <math.h>

double	distance(double z_mag_sq, t_complex dz, double power)
{
	double	distance;
	double	k;

	distance = log(z_mag_sq) * 0.5f * \
		sqrt(z_mag_sq / mag_squared(dz.real, dz.imag));
	k = 25;
	k = (1./sqrt(distance)) * (k * k + .25f);
	return (log(log(z_mag_sq) / power) * k);
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
