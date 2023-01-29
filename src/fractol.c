/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:10 by arobu             #+#    #+#             */
/*   Updated: 2023/01/29 13:23:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol(void)
{
	t_program	data;
	int32_t		curr_x;
	int32_t		curr_y;
	
	data.fractals = create_fractal_stack();
	add_new_fractal(&data.fractals, MANDELBROT);
	data.window = render_window(&data.renderer);
	render_fractal_viewport(&data.renderer, data.fractals->front, \
								data.window, MANDELBROT);
	ft_printf("Top Left: [%d, %d]\t", data.window.corners.top_left.x, data.window.corners.top_left.y);
	ft_printf("Top Right: [%d, %d]\t", data.window.corners.top_right.x, data.window.corners.top_right.y);
	ft_printf("Bottom Right: [%d, %d]\t", data.window.corners.bottom_right.x, data.window.corners.bottom_right.y);
	ft_printf("Bottom Left: [%d, %d]\n", data.window.corners.bottom_left.x, data.window.corners.bottom_left.y);
	mlx_key_hook(data.renderer.mlx, (mlx_keyfunc) key_hooks, &data);
	mlx_resize_hook(data.renderer.mlx, (mlx_resizefunc) resize_hooks, &data);
	rendering_loop(&data.renderer);
	mlx_terminate(data.renderer.mlx);
}
/*
f(-2, 1, -1, 1);
*/