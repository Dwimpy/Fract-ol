/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:06 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 17:02:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	redraw_julia(t_program *data)
{
	t_viewport	*viewport;

	if (data->args.julia == true)
	{
		viewport = &data->fractals->front->viewport;
		mlx_get_mouse_pos(data->renderer.mlx, &data->mouse.x, &data->mouse.y);
		data->args.var.real = viewport->boundary.x_min + \
								data->mouse.x * viewport->pixel_size;
		data->args.var.imag = viewport->boundary.y_max - \
								data->mouse.y * viewport->pixel_size;
		data->args.is_redrawing = 1;
		initialize_fractal(data);
		render_viewport(data, (t_render_iter){0}, DEFAULT);
	}
}
