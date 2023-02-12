/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_distances.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:05:50 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 21:04:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/fractals.h"

t_pixel_data	*distance(t_pixel_data *data, double z_mag_sq, t_complex dz)
{
	data->distance = log(z_mag_sq) * 0.5f * \
		sqrt(z_mag_sq / mag_squared(dz.real, dz.imag));
	data->iteration.zone = OUTSIDE;
	data->potential = log(log(z_mag_sq) / \
					powf(2, data->iteration.iteration));
	return (data);
}

t_pixel_data	*on_boundary(t_pixel_data *data, uint32_t iteration)
{
	data->iteration.iteration = iteration;
	data->iteration.zone = BOUNDARY;
	return (data);
}

int	periodicty_checking(t_complex z, t_complex saved, \
					int *check, double pixel_size)
{
	if (*check == 1)
	{
		if (mangnitude(z.real - saved.real, z.imag - saved.imag) < \
			pixel_size)
			return (1);
	}
	else
		*check = 0;
	return (0);
}

void	save_z(t_complex *saved_z, double real, double imag, int *check)
{
	set_complex(saved_z, real, imag);
	*check = 1;
}
