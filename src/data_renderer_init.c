/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_renderer_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:03 by arobu             #+#    #+#             */
/*   Updated: 2023/02/09 20:08:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	default_behavior(t_program *data, t_render_iter *iter);
static void	custom_behavior(t_render_iter *iter);

void	init_behavior(t_program *data, \
					t_render_iter *iter, t_render_enum type)
{
	if (type == DEFAULT)
		default_behavior(data, iter);
	else if (type == CUSTOM)
		custom_behavior(iter);
}

static void	default_behavior(t_program *data, t_render_iter *iter)
{
	iter->from_col = -1;
	iter->from_row = -1;
	iter->to_col = data->fractals->front->viewport.size.width;
	iter->to_row = data->fractals->front->viewport.size.height;
}

static void	custom_behavior(t_render_iter *iter)
{
	iter->from_col -= 1;
	iter->from_row -= 1;
}

t_render_iter	set_offset(uint32_t from_col, uint32_t from_row, \
							uint32_t to_col, uint32_t to_row)
{
	t_render_iter	iter;

	iter.from_col = from_col;
	iter.from_row = from_row;
	iter.to_col = to_col;
	iter.to_row = to_row;
	return (iter);
}
