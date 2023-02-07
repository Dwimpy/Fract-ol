/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_animation_translation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:02:24 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 15:17:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	anim_known_right(t_program *data, uint32_t offset_x);
static void	anim_known_left(t_program *data, uint32_t offset_x);
static void	anim_known_up(t_program *data, uint32_t offset_y);
static void	anim_known_down(t_program *data, uint32_t offset_y);

void	anim_translation(t_program *data, uint32_t offset, t_dir direction)
{
	if (direction == RIGHT)
		anim_known_right(data, offset);
	else if (direction == LEFT)
		anim_known_left(data, offset);
	else if (direction == UP)
		anim_known_up(data, offset);
	else if (direction == DOWN)
		anim_known_down(data, offset);
}

static void	anim_known_right(t_program *data, uint32_t offset_x)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;
	int				j;
	int				i;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map;
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

static void	anim_known_left(t_program *data, uint32_t offset_x)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;
	int				j;
	int				i;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map + (window->settings.width * \
					window->settings.height) - 1;
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

static void	anim_known_up(t_program *data, uint32_t offset_y)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;
	int				i;
	int				j;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map + (window->settings.width * \
						window->settings.height) - 1;
	copy_from = copy_to - offset_y * window->settings.width;
	j = -1;
	while (++j < window->settings.height - offset_y)
	{
		i = -1;
		while (++i < window->settings.width)
			*copy_to-- = *copy_from--;
	}
}

static void	anim_known_down(t_program *data, uint32_t offset_y)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;
	int				i;
	int				j;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map;
	copy_from = copy_to + offset_y * window->settings.width;
	j = -1;
	while (++j < window->settings.height - offset_y)
	{
		i = -1;
		while (++i < window->settings.width)
			*copy_to++ = *copy_from++;
	}
}
