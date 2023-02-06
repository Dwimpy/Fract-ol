/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_renderer_julia_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:00:10 by arobu             #+#    #+#             */
/*   Updated: 2023/02/04 15:23:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	init_julia(t_program *data, t_render_iter *iter, int32_t *start_col)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	*start_col = iter->from_col;
	viewport->data.z.imag = viewport->boundary.y_max - \
						viewport->pixel_size * (iter->from_row);
}
