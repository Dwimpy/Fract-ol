/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_zoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:17:37 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 02:29:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	zoom(t_program *data, double ydelta, double scale)
{
	t_viewport	*viewport;
	double		real;
	double		imag;

	viewport = &data->fractals->front->viewport;
	real = viewport->boundary.x_min + data->mouse.x * viewport->pixel_size;
	imag = viewport->boundary.y_max - data->mouse.y * viewport->pixel_size;
	if (ydelta > 0)
		set_pixel_size(viewport, viewport->pixel_size / scale);
	else
		set_pixel_size(viewport, viewport->pixel_size * scale);
	set_viewport_centers(viewport, real, imag);
	set_viewport_boundaries_zoom(viewport, data->mouse.x, data->mouse.y);
	set_viewport_centers(viewport, \
						viewport->boundary.x_min + \
						viewport->pixel_size * viewport->size.width / 2, \
						viewport->boundary.y_max - \
						viewport->pixel_size * viewport->size.height / 2);
}
