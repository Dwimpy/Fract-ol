/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:37:18 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 19:01:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	move_right(t_program *data);
static void	move_left(t_program *data);
static void	move_up(t_program *data);
static void	move_down(t_program *data);

void	handle_movement(t_program *data)
{
	if (data->controller_flag & 0x0)
		return ;
	if (data->controller_flag & RIGHT)
		move_right(data);
	if (data->controller_flag & LEFT)
		move_left(data);
	if (data->controller_flag & UP)
		move_up(data);
	if (data->controller_flag & DOWN)
		move_down(data);
}

static void	move_right(t_program *data)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	render_and_translate(data, 20, \
	set_offset(viewport->size.width - 20, 0, \
	viewport->size.width, \
	viewport->size.height), RIGHT);
}

static void	move_left(t_program *data)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	render_and_translate(data, 20, \
	set_offset(0, 0, 20, viewport->size.height), LEFT);
}

static void	move_up(t_program *data)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	render_and_translate(data, 20, \
	set_offset(0, 0, viewport->size.width, 20), UP);
}

static void	move_down(t_program *data)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	render_and_translate(data, 20, \
	set_offset(0, viewport->size.height - 20, \
	viewport->size.width, viewport->size.height), DOWN);
}
