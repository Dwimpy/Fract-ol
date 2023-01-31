/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_translation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:12:43 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 17:29:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	render_known_right(t_program *data, uint32_t offset_x)
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

void	render_known_left(t_program *data, uint32_t offset_x)
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

void	render_known_up(t_program *data, uint32_t offset_y)
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

void	render_known_down(t_program *data, uint32_t offset_y)
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
