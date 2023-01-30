/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:10 by arobu             #+#    #+#             */
/*   Updated: 2023/01/30 19:16:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol(void)
{
	t_program	data;

	data.fractals = create_fractal_stack();
	data.window = render_window(&data.renderer);
	add_new_fractal(&data.fractals, &data.window, MANDELBROT);
	render_fractal_viewport(&data.renderer, data.fractals->front, \
								data.window, MANDELBROT);
	mlx_key_hook(data.renderer.mlx, (mlx_keyfunc) key_hooks, &data);
	mlx_resize_hook(data.renderer.mlx, (mlx_resizefunc) resize_hooks, &data);
	mlx_loop(data.renderer.mlx);
	mlx_terminate(data.renderer.mlx);
}
/*
f(-2, 1, -1, 1);
*/