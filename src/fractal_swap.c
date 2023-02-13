/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:32:40 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 17:41:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	set_type(t_program *data, int mandel, int julia, int tricorn);

void	swap_fractal(t_program *data, action_t action, int key)
{
	if (key == MLX_KEY_M && action == MLX_PRESS)
		if (data->args.mandelbrot == false)
			set_type(data, true, false, false);
	if (key == MLX_KEY_J && action == MLX_PRESS)
		if (data->args.julia == false)
			set_type(data, false, true, false);
	if (key == MLX_KEY_T && action == MLX_PRESS)
		if (data->args.tricorn == false)
			set_type(data, false, false, true);
}

static void	set_type(t_program *data, int mandel, int julia, int tricorn)
{
	data->args.mandelbrot = mandel;
	data->args.julia = julia;
	data->args.tricorn = tricorn;
	initialize_fractal(data);
	render_viewport(data, (t_render_iter){0}, DEFAULT);
}
