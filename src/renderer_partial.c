/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_partial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:30:13 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 17:31:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	render_fractal_horizontal(t_program *data, \
										int32_t start_pixel, \
											int32_t offset_x)
{
	t_window		*window;
	t_viewport		*viewport;
	t_iteration		iteration;
	int				i;
	int				j;

	viewport = &data->fractals->front->viewport;
	window = &data->window;
	j = -1;
	viewport->data.c.imag = viewport->boundary.y_max;
	while (++j < window->settings.height)
	{
		i = start_pixel - 1;
		viewport->data.c.real = viewport->boundary.x_min + \
									viewport->pixel_size * start_pixel;
		while (++i < start_pixel + offset_x)
		{
			iteration = distance_estimation(viewport->pixel_size, \
												&viewport->data.z, \
													&viewport->data.c);
			if (iteration.zone == BOUNDARY)
				mlx_put_pixel(data->fractals->front->image, i, j, 0x0000FFFF);
			else if (iteration.zone == OUTSIDE)
				mlx_put_pixel(data->fractals->front->image, i, j, 0xFF00003a);
			else
				mlx_put_pixel(data->fractals->front->image, i, j, 0x000000FF);
			viewport->data.c.real += viewport->pixel_size;
		}
		viewport->data.c.imag -= viewport->pixel_size;
	}
}

void	render_fractal_vertical(t_program *data, \
									int32_t from_row, \
										int32_t to_row,
											int32_t cx_offset)
{
	t_window		*window;
	t_viewport		*viewport;
	t_iteration		iteration;
	int				i;
	int				j;

	viewport = &data->fractals->front->viewport;
	window = &data->window;
	j = from_row - 1;
	viewport->data.c.imag = viewport->boundary.y_max - \
								viewport->pixel_size * \
									cx_offset;
	while (++j < to_row)
	{
		i = -1;
		viewport->data.c.real = viewport->boundary.x_min;
		while (++i < window->settings.width)
		{
			iteration = distance_estimation(viewport->pixel_size, \
												&viewport->data.z, \
													&viewport->data.c);
			if (iteration.zone == BOUNDARY)
				mlx_put_pixel(data->fractals->front->image, i, j, 0x0000FFFF);
			else if (iteration.zone == OUTSIDE)
				mlx_put_pixel(data->fractals->front->image, i, j, 0xFF00003a);
			else
				mlx_put_pixel(data->fractals->front->image, i, j, 0x000000FF);
			viewport->data.c.real += viewport->pixel_size;
		}
		viewport->data.c.imag -= viewport->pixel_size;
	}
}
