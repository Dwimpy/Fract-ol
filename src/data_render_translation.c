/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_render_translation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:12:43 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 15:17:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	render_known_right(t_program *data, uint32_t offset_x);
static void	render_known_left(t_program *data, uint32_t offset_x);
static void	render_known_up(t_program *data, uint32_t offset_y);
static void	render_known_down(t_program *data, uint32_t offset_y);

void	render_translation(t_program *data, uint32_t offset, t_dir direction)
{
	if (direction == RIGHT)
		render_known_right(data, offset);
	else if (direction == LEFT)
		render_known_left(data, offset);
	else if (direction == UP)
		render_known_up(data, offset);
	else if (direction == DOWN)
		render_known_down(data, offset);
}

static void	render_known_right(t_program *data, uint32_t offset_x)
{
	t_window		*window;
	uint32_t		*copy_to;
	uint32_t		*copy_from;
	int				j;
	int				i;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels;
	copy_from = copy_to + offset_x;
	j = -1;
	while (++j < window->settings.height)
	{
		i = -1;
		while (++i < window->settings.width - offset_x)
			*copy_to++ = *copy_from++;
		copy_to += offset_x;
		copy_from += offset_x;
	}
}

static void	render_known_left(t_program *data, uint32_t offset_x)
{
	t_window		*window;
	uint32_t		*copy_to;
	uint32_t		*copy_from;
	int				j;
	int				i;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels + \
				window->settings.width * window->settings.height - 1;
	copy_from = copy_to - offset_x;
	j = -1;
	while (++j < window->settings.height)
	{
		i = -1;
		while (++i < window->settings.width - offset_x)
			*copy_to-- = *copy_from--;
		copy_to -= offset_x;
		copy_from -= offset_x;
	}
}

static void	render_known_up(t_program *data, uint32_t offset_y)
{
	t_window		*window;
	uint32_t		*copy_to;
	uint32_t		*copy_from;
	int				i;
	int				j;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels + \
		window->settings.width * (window->settings.height) - 1;
	copy_from = copy_to - offset_y * window->settings.width;
	j = -1;
	while (++j < window->settings.height - offset_y)
	{
		i = -1;
		while (++i < window->settings.width)
			*copy_to-- = *copy_from--;
	}

}

static void	render_known_down(t_program *data, uint32_t offset_y)
{
	t_window		*window;
	uint32_t		*copy_to;
	uint32_t		*copy_from;
	int				i;
	int				j;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels;
	copy_from = copy_to + offset_y * window->settings.width;
	j = -1;
	while (++j < window->settings.height - offset_y)
	{
		i = -1;
		while (++i < window->settings.width)
			*copy_to++ = *copy_from++;
	}
}
