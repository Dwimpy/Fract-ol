/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:13:28 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 22:08:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	movement_hook(t_program *data)
{
	if ((data->controller_flag & RIGHT) && \
			mlx_is_key_down(data->renderer.mlx, MLX_KEY_RIGHT))
		if (!(data->controller_flag & LEFT))
			move_right(data, RIGHT);
	if ((data->controller_flag & LEFT) && \
			mlx_is_key_down(data->renderer.mlx, MLX_KEY_LEFT))
		if (!(data->controller_flag & RIGHT))
			move_left(data, LEFT);
	if ((data->controller_flag & UP) && \
			mlx_is_key_down(data->renderer.mlx, MLX_KEY_UP))
		if (!(data->controller_flag & DOWN))
			move_up(data, UP);
	if ((data->controller_flag & DOWN) && \
			mlx_is_key_down(data->renderer.mlx, MLX_KEY_DOWN))
		if (!(data->controller_flag & UP))
			move_down(data, DOWN);
}

void		scroll_hook(double xdelta, double ydelta, t_program *data)
{
	if (ydelta)
	{
		mlx_get_mouse_pos(data->renderer.mlx, &data->mouse.x, &data->mouse.y);
		zoom(data, ydelta, 1.5);
		render_viewport(&data->renderer, data->fractals->front, \
							data->window);
	}
}

void	key_hooks(mlx_key_data_t keydata, t_program *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->renderer.mlx);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || \
											keydata.action == MLX_RELEASE))
		update_direction(data, keydata.action, RIGHT);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || \
											keydata.action == MLX_RELEASE))
		update_direction(data, keydata.action, LEFT);
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || \
											keydata.action == MLX_RELEASE))
		update_direction(data, keydata.action, UP);
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || \
											keydata.action == MLX_RELEASE))
		update_direction(data, keydata.action, DOWN);
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
