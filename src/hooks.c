/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:13:28 by arobu             #+#    #+#             */
/*   Updated: 2023/01/30 17:45:17 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	key_hooks(mlx_key_data_t keydata, t_program *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->renderer.mlx);
	if (keydata.key == MLX_KEY_RIGHT && \
			(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		translate_right(data, 20);
		render_known_right(data, 20);
		render_fractal_horizontal(data, data->window.settings.width - 20, 20);
	}
	if (keydata.key == MLX_KEY_LEFT && \
			(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		translate_left(data, 20);
		render_known_left(data, 20);
		render_fractal_horizontal(data, 0, 20);
	}
}

void	resize_hooks(int32_t new_width, int32_t new_height, t_program *data)
{
	t_screen_left	screen_left;
	t_corners		corners;

	screen_left = data->window.screen_coords;
	corners = data->window.corners;
	resize_window(&data->window, new_width, new_height);
	set_corners(&data->window, data->renderer.mlx, &mlx_get_window_pos);
	mlx_resize_image(data->fractals->front->image, \
						data->window.settings.width, \
							data->window.settings.height);
	set_viewport_size(&data->fractals->front->viewport, \
						(*data).window.settings.width, \
							(*data).window.settings.height);
	set_viewport_boundary(&data->fractals->front->viewport);
	render_fractal_viewport(&data->renderer, \
								data->fractals->front, \
									(data->window), MANDELBROT);
}
