/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_distance_estimations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:28:14 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 21:37:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

t_pixel_data	*mandelbrot_de(double pixel_size, \
					t_complex *z, \
					t_complex *c,
					t_pixel_data *pixel_map)
{
	double			mag_sq;
	t_complex		dz;
	t_complex		dc;

	pixel_map->iteration.iteration = 0;
	set_complex(z, c->real, c->imag);
	set_complex(&dc, (1 * pixel_size * THICKNESS), 0);
	set_complex(&dz, dc.real, dc.imag);
	pixel_map->iteration.zone = INSET;
	while (pixel_map->iteration.iteration < MAX_DEPTH)
	{
		mag_sq = mag_squared(z->real, z->imag);
		if (mag_sq < mag_squared(dz.real, dz.imag))
			return (on_boundary(pixel_map, pixel_map->iteration.iteration));
		if (mag_sq > RADIUS * RADIUS)
			return (distance(pixel_map, mag_sq, dz));
		mandelbrot_der_equation(&dz, z, dc);
		mandelbrot_equation(z, c);
		pixel_map->iteration.iteration++;
	}
	return (pixel_map);
}

// t_pixel_data	julia_de(double pixel_size, \
// 					t_complex *z, \
// 					t_complex *c)
// {
// 	double		mag_sq;
// 	t_complex	dz;
// 	t_complex	dc;
// 	t_complex	julia_z;
// 	t_iteration	iteration;

// 	iteration.iteration = 0;
// 	julia_z.real = z->real;
// 	julia_z.imag = z->imag;
// 	set_complex(&dc, (1 * pixel_size * THICKNESS), 0);
// 	set_complex(&dz, dc.real, dc.imag);
// 	while (iteration.iteration < MAX_DEPTH)
// 	{
// 		mag_sq = mag_squared(julia_z.real, julia_z.imag);
// 		if (mag_sq < mag_squared(dz.real, dz.imag))
// 			return ((t_iteration){iteration.iteration, BOUNDARY, 0.});
// 		if (mag_sq > RADIUS * RADIUS)
// 			return ((t_iteration){iteration.iteration, \
// 				OUTSIDE, distance(mag_sq, dz, powf(2, iteration.iteration))});
// 		mandelbrot_der_equation(&dz, &julia_z, dc);
// 		mandelbrot_equation(&julia_z, c);
// 		iteration.iteration++;
// 	}	
// 	return ((t_iteration){iteration.iteration, INSET, 0.});
// }
