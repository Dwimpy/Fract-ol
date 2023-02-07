/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:13:28 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 02:06:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	movement_hook(t_program *data)
{
	handle_movement(data);
	if (mlx_is_key_down(data->renderer.mlx, MLX_KEY_P))
	{
		animate(data);
	}
}

void	scroll_hook(double xdelta, double ydelta, t_program *data)
{
	if (ydelta)
	{
		mlx_get_mouse_pos(data->renderer.mlx, &data->mouse.x, &data->mouse.y);
		zoom(data, ydelta, 1.5);
		render_viewport(data, (t_render_iter){0}, DEFAULT);
	}
}

void	key_hooks(mlx_key_data_t keydata, t_program *data)
{
	handle_keys(data, keydata.action, keydata.key);}

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
	render_viewport(data, (t_render_iter){0}, DEFAULT);
}
