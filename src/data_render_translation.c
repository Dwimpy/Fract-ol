/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_render_translation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:12:43 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 22:50:12 by arobu            ###   ########.fr       */
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
	t_window	*window;
	uint32_t	*copy_to;
	uint32_t	*copy_from;
	int			j;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels;
	copy_from = copy_to + offset_x;
	j = -1;
	while (++j < window->settings.height)
	{
		ft_memmove(copy_to, \
					copy_from, \
						(window->settings.width - offset_x) * sizeof(int));
		copy_to += window->settings.width;
		copy_from += window->settings.width;
	}
}

static void	render_known_left(t_program *data, uint32_t offset_x)
{
	t_window	*window;
	uint32_t	*copy_to;
	uint32_t	*copy_from;
	int			j;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels;
	copy_from = copy_to;
	j = -1;
	while (++j < window->settings.height)
	{
		ft_memmove(copy_to + offset_x, copy_from, \
						(window->settings.width - offset_x) * \
							sizeof(int));
		copy_to += window->settings.width;
		copy_from += window->settings.width;
	}
}

static void	render_known_up(t_program *data, uint32_t offset_y)
{
	t_window	*window;
	uint32_t	*copy_to;
	uint32_t	*copy_from;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels;
	copy_from = copy_to;
	ft_memmove(copy_to + offset_y * window->settings.width, copy_from, \
						(window->settings.height - offset_y) * \
							window->settings.width * sizeof(int));
}

static void	render_known_down(t_program *data, uint32_t offset_y)
{
	t_window	*window;
	uint32_t	*copy_to;
	uint32_t	*copy_from;

	window = &data->window;
	copy_to = (uint32_t *)data->fractals->front->image->pixels;
	copy_from = copy_to;
	ft_memmove(copy_to, copy_from + offset_y * window->settings.width, \
						(window->settings.height - offset_y) * \
							window->settings.width * sizeof(int));
}
