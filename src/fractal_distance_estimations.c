/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_distance_estimations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:28:14 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 22:11:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"
#include "../include/compute_args.h"

t_pixel_data	*mandelbrot_de(double pixel_size, \
					t_complex *z, \
					t_complex *c,
					t_pixel_data *pixel_map)
{
	t_compute_args	args;

	set_complex(z, c->real, c->imag);
	initialize_values(&args.dc, &args.dz, pixel_size);
	init_map_period(pixel_map, &args.saved_z, &args.check);
	if (bulb_checking(pixel_map, *c) == 1)
		return (pixel_map);
	while (pixel_map->iteration.iteration < MAX_DEPTH)
	{
		args.mag_sq = mag_squared(z->real, z->imag);
		if (args.mag_sq < mag_squared(args.dz.real, args.dz.imag))
			return (on_boundary(pixel_map, pixel_map->iteration.iteration));
		if (args.mag_sq > RADIUS * RADIUS)
			return (distance(pixel_map, args.mag_sq, args.dz));
		mandelbrot_der_equation(&args.dz, z, args.dc);
		mandelbrot_equation(z, c);
		if (periodicty_checking(*z, args.saved_z, &args.check, pixel_size) == 1)
			return (pixel_map);
		if (pixel_map->iteration.iteration % 20 == 0)
			save_z(&args.saved_z, z->real, z->imag, &args.check);
		pixel_map->iteration.iteration++;
	}
	return (pixel_map);
}

t_pixel_data	*julia_de(double pixel_size, \
					t_complex *c, \
					t_complex *z,
					t_pixel_data *pixel_map)
{	
	double		mag_sq;
	t_complex	dz;
	t_complex	dc;
	t_complex	julia_z;

	pixel_map->iteration.iteration = 0;
	julia_z.real = z->real;
	julia_z.imag = z->imag;
	set_complex(&dc, (1 * pixel_size * THICKNESS), 0);
	set_complex(&dz, dc.real, dc.imag);
	pixel_map->iteration.zone = INSET;
	while (pixel_map->iteration.iteration < MAX_DEPTH)
	{
		mag_sq = mag_squared(julia_z.real, julia_z.imag);
		if (mag_sq < mag_squared(dz.real, dz.imag))
			return (on_boundary(pixel_map, pixel_map->iteration.iteration));
		if (mag_sq > RADIUS * RADIUS)
			return (distance(pixel_map, mag_sq, dz));
		mandelbrot_der_equation(&dz, &julia_z, dc);
		mandelbrot_equation(&julia_z, c);
			pixel_map->iteration.iteration++;
	}	
	return (pixel_map);
}

t_pixel_data	*tricorn_de(double pixel_size, \
					t_complex *z, \
					t_complex *c,
					t_pixel_data *pixel_map)
{	
	double		mag_sq;
	t_complex	dz;
	t_complex	dc;

	pixel_map->iteration.iteration = 0;
	set_complex(z, c->real, c->imag);
	set_complex(&dc, (1 * pixel_size * THICKNESS), 0);
	set_complex(&dz, dc.real, dc.imag);
	pixel_map->iteration.zone = INSET;
	while (pixel_map->iteration.iteration < MAX_DEPTH)
	{
		conjugate(z, z->real, z->imag);
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
