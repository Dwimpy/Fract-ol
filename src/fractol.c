/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:10 by arobu             #+#    #+#             */
/*   Updated: 2023/02/02 18:14:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol(void)
{
	t_program	data;

	data.controller_flag = 0x0;
	data.fractals = create_fractal_stack();
	data.window = render_window(&data.renderer);
	add_new_fractal(&data.fractals, &data.window, MANDELBROT);
	render_fractal_viewport(&data.renderer, data.fractals->front, \
								data.window, MANDELBROT);
	mlx_loop_hook(data.renderer.mlx, (void *) movement_hook, &data);
	mlx_key_hook(data.renderer.mlx, (mlx_keyfunc) key_hooks, &data);
	mlx_scroll_hook(data.renderer.mlx, (mlx_scrollfunc) scroll_hook, &data);
	mlx_resize_hook(data.renderer.mlx, (mlx_resizefunc) resize_hooks, &data);
	mlx_loop(data.renderer.mlx);
	mlx_terminate(data.renderer.mlx);
}
