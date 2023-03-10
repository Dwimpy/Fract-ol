/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:33:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 01:23:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	set_data_references(t_program *data, t_viewport **viewport, \
								t_fractal_node **fractal);
static void	render_func(t_program *data, t_render_iter iter);
static void	render_loop(t_program *data, t_viewport *viewport, \
					t_fractal_node *fractal, t_render_iter it);

void	render_viewport(t_program *data, t_render_iter	iter, \
						t_render_enum type)
{
	init_behavior(data, &iter, type);
	render_func(data, iter);
}

void	render_and_translate(t_program *data, int32_t offset, \
							t_render_iter iter, t_dir direction)
{
	translate_viewport(data, offset, direction);
	if (data->args.is_animated == true)
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

static void	render_func(t_program *data, t_render_iter it)
{
	t_viewport		*viewport;
	t_fractal_node	*fractal;

	set_data_references(data, &viewport, &fractal);
	render_loop(data, viewport, fractal, it);
}

static void	render_loop(t_program *data, t_viewport *viewport, \
					t_fractal_node *fractal, t_render_iter it)
{
	int32_t			start_col;
	int32_t			r_index;

	start_col = it.from_col;
	if (!data->args.is_animated)
		data->k = 4.;
	viewport->data.var.imag = viewport->boundary.y_max - \
						viewport->pixel_size * (it.from_row);
	while (++it.from_row < it.to_row)
	{
		it.from_col = start_col;
		r_index = it.from_row * viewport->size.width;
		viewport->data.var.real = viewport->boundary.x_min + \
								viewport->pixel_size * (it.from_col);
		while (++it.from_col < it.to_col)
		{
			data->equation(viewport->pixel_size, &viewport->data.constant, \
			&viewport->data.var, &data->pixel_map[r_index + it.from_col]);
			mlx_put_pixel(fractal->image, it.from_col, it.from_row, \
			put_pixel_color(&data->pixel_map[r_index + it.from_col], \
							data->args.color, data->k));
			viewport->data.var.real += viewport->pixel_size;
		}
		viewport->data.var.imag -= viewport->pixel_size;
	}
}
