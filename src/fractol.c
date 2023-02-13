/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:10 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 17:31:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol(t_arg_opts *args)
{
	t_program	data;

	data.controller_flag = 0x0;
	data.args = *args;
	data.pixel_map = init_pixel_map();
	create_fractal_stack(&data.fractals);
	data.window = render_window(&data.renderer);
	add_new_fractal(&data.fractals);
	initialize_fractal(&data);
	render_viewport(&data, (t_render_iter){0}, DEFAULT);
	mlx_loop_hook(data.renderer.mlx, (void *) movement_hook, &data);
	mlx_key_hook(data.renderer.mlx, (mlx_keyfunc) key_hooks, &data);
	mlx_scroll_hook(data.renderer.mlx, (mlx_scrollfunc) scroll_hook, &data);
	mlx_resize_hook(data.renderer.mlx, (mlx_resizefunc) resize_hooks, &data);
	mlx_loop(data.renderer.mlx);
	destroy_stack(&data.fractals, data.renderer.mlx);
	free(data.pixel_map);
	mlx_terminate(data.renderer.mlx);
}
