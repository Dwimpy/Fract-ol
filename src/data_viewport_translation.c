/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_viewport_translation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:15:52 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 19:13:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	translate_right(t_program *data, uint32_t offset);
static void	translate_left(t_program *data, uint32_t offset);
static void	translate_up(t_program *data, uint32_t offset);
static void	translate_down(t_program *data, uint32_t offset);

void	translate_viewport(t_program *data, uint32_t offset, t_dir direction)
{
	if (direction == RIGHT)
		translate_right(data, offset);
	else if (direction == LEFT)
		translate_left(data, offset);
	else if (direction == UP)
		translate_up(data, offset);
	else if (direction == DOWN)
		translate_down(data, offset);
}

static void	translate_right(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cx += viewport->pixel_size * offset;
	set_viewport_boundary(viewport);
}

static void	translate_left(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cx -= viewport->pixel_size * offset;
	set_viewport_boundary(viewport);
}

static void	translate_up(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cy += viewport->pixel_size * offset;
	set_viewport_boundary(viewport);
}

static void	translate_down(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cy -= viewport->pixel_size * offset;
	set_viewport_boundary(viewport);
}
