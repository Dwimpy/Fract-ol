/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:13:28 by arobu             #+#    #+#             */
/*   Updated: 2023/01/29 14:46:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	*key_hooks(mlx_key_data_t keydata, t_program *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->renderer.mlx);
	if (mlx_is_key_down(data->renderer.mlx, MLX_KEY_A) == true)
		ft_printf("WTF");
}

void	*resize_hooks(int32_t new_width, int32_t new_height, t_program *data)
{
	int left;
	int top;
	int right;
	int bottom;
	
	resize_window(&data->window, new_width, new_height);
	mlx_get_viewport(data->renderer.mlx, &left, &top, &right, &bottom);
	ft_printf("Left: [%d]\tTop: [%d]\tRight: [%d]\tBottom: [%d]\n", left, top, right, bottom);
	set_corners(&data->window, data->renderer.mlx, &mlx_get_window_pos);
	
	//ft_printf("[%d, %d]\n", curr_x, curr_y);
	// ft_printf("Top Left: [%d, %d]\t", data->window.corners.top_left.x, data->window.corners.top_left.y);
	// ft_printf("Top Right: [%d, %d]\t", data->window.corners.top_right.x, data->window.corners.top_right.y);
	// ft_printf("Bottom Right: [%d, %d]\t", data->window.corners.bottom_right.x, data->window.corners.bottom_right.y);
	// ft_printf("Bottom Left: [%d, %d]\n", data->window.corners.bottom_left.x, data->window.corners.bottom_left.y);
	mlx_resize_image(data->fractals->front->image, \
						data->window.settings.width, \
							data->window.settings.height);
	render_fractal_viewport(&data->renderer, \
								data->fractals->front, \
									(data->window), MANDELBROT);
	
}