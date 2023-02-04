/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:41:11 by arobu             #+#    #+#             */
/*   Updated: 2023/02/04 01:09:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"
#include <math.h>

double	color(double z_mag_sq)
{
	return (log(log(z_mag_sq)) / log(2));
}

double	distance(double z_mag_sq, t_complex dz)
{
	return (log(z_mag_sq) * \
		sqrt(z_mag_sq) / mag_squared(dz.real, dz.imag));
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
