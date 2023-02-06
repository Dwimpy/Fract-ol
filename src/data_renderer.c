/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:33:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 22:47:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	set_data_references(t_program *data, t_viewport **viewport, \
								t_fractal_node **fractal);
static void	render_func(t_program *data, t_render_iter iter);

void	render_viewport(t_program *data, t_render_iter	iter, \
						t_render_enum type)
{
	init_behavior(data, &iter, type);
	if (data->fractals->front->name == MANDELBROT)
		render_func(data, iter);
	// if (data->fractals->front->name == JULIA)
	// 	render_func_julia(data, iter);
}

void	render_and_translate(t_program *data, int32_t offset, \
							t_render_iter iter, t_dir direction)
{
	translate_viewport(data, offset, direction);
	anim_translation(data, offset, direction);
	render_translation(data, offset, direction);
	render_viewport(data, iter, CUSTOM);
}

static void	set_data_references(t_program *data, t_viewport **viewport, \
								t_fractal_node **fractal)
{
	*viewport = &data->fractals->front->viewport;
	*fractal = data->fractals->front;
}

static void	render_func(t_program *data, t_render_iter iter)
{
	t_viewport		*viewport;
	t_fractal_node	*fractal;
	int32_t			start_col;
	int32_t			row_index;

	set_data_references(data, &viewport, &fractal);
	start_col = iter.from_col;
	viewport->data.c.imag = viewport->boundary.y_max - \
						viewport->pixel_size * (iter.from_row);
	while (++iter.from_row < iter.to_row)
	{
		iter.from_col = start_col;
		row_index = iter.from_row * viewport->size.width;
		viewport->data.c.real = viewport->boundary.x_min + \
								viewport->pixel_size * (iter.from_col);
		while (++iter.from_col < iter.to_col)
		{
			mandelbrot_de(viewport->pixel_size, &viewport->data.z, \
			&viewport->data.c, &data->pixel_map[row_index + iter.from_col]);
			mlx_put_pixel(fractal->image, iter.from_col, iter.from_row, \
							put_pixel_color(&data->pixel_map[row_index + \
															iter.from_col]));
			viewport->data.c.real += viewport->pixel_size;
		}
		viewport->data.c.imag -= viewport->pixel_size;
	}
}

// void	render_func_julia(t_program *data, t_render_iter iter)
// {
// 	t_viewport		*viewport;
// 	t_fractal_node	*fractal;
// 	int32_t			start_col;
// 	t_iteration		iteration;

// 	set_data_references(data, &viewport, &fractal);
// 	init_julia(data, &iter, &start_col);
// 	while (++iter.from_row < iter.to_row)
// 	{
// 		iter.from_col = start_col;
// 		viewport->data.z.real = viewport->boundary.x_min + \
// 								viewport->pixel_size * (iter.from_col);
// 		while (++iter.from_col < iter.to_col)
// 		{
// 			iteration = julia_de(viewport->pixel_size, \
// 									&viewport->data.z, &viewport->data.c);
// 			mlx_put_pixel(fractal->image, iter.from_col, iter.from_row, \
// 							put_pixel_color(iteration));
// 			viewport->data.z.real += viewport->pixel_size;
// 		}
// 		viewport->data.z.imag -= viewport->pixel_size;
// 	}
// }

// void	render_func_burning_ship(t_program *data, \
// 								t_render_iter iter, t_complex c)
// {
// 	t_viewport		*viewport;
// 	t_fractal_node	*fractal;
// 	int32_t			start_col;
// 	t_iteration		iteration;

// 	set_data_references(data, &viewport, &fractal);
// 	init_behavior(data, &iter, DEFAULT);
// 	start_col = iter.from_col;
// 	viewport->data.c = c;
// 	viewport->data.z.imag = viewport->boundary.y_max - \
// 						viewport->pixel_size * (iter.from_row);
// 	while (++iter.from_row < iter.to_row)
// 	{
// 		iter.from_col = start_col;
// 		viewport->data.z.real = viewport->boundary.x_min + \
// 								viewport->pixel_size * (iter.from_col);
// 		while (++iter.from_col < iter.to_col)
// 		{
// 			iteration = burning_ship_distance_estimation(viewport->pixel_size, \
// 									&viewport->data.z, &viewport->data.c);
// 			mlx_put_pixel(fractal->image, iter.from_col, iter.from_row, \
// 							put_pixel_color(iteration));
// 			viewport->data.z.real += viewport->pixel_size;
// 		}
// 		viewport->data.z.imag -= viewport->pixel_size;
// 	}
// }
