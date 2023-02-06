/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_animation_translation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:02:24 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 22:51:13 by arobu            ###   ########.fr       */
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

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map;
	copy_from = copy_to + offset_x;
	j = -1;
	while (++j < window->settings.height)
	{
		ft_memmove(copy_to, \
					copy_from, \
						(window->settings.width - offset_x) * \
							sizeof(t_pixel_data));
		copy_to += window->settings.width;
		copy_from += window->settings.width;
	}
}

static void	anim_known_left(t_program *data, uint32_t offset_x)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;
	int				j;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map;
	copy_from = copy_to;
	j = -1;
	while (++j < window->settings.height)
	{
		ft_memmove(copy_to + offset_x, copy_from, \
						(window->settings.width - offset_x) * \
							sizeof(t_pixel_data));
		copy_to += window->settings.width;
		copy_from += window->settings.width ;
	}
}

static void	anim_known_up(t_program *data, uint32_t offset_y)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map;
	copy_from = copy_to;
	ft_memmove(copy_to + offset_y * window->settings.width, copy_from, \
						(window->settings.height - offset_y) * \
							window->settings.width * sizeof(t_pixel_data));
}

static void	anim_known_down(t_program *data, uint32_t offset_y)
{
	t_window		*window;
	t_pixel_data	*copy_to;
	t_pixel_data	*copy_from;

	window = &data->window;
	copy_to = (t_pixel_data *)data->pixel_map;
	copy_from = copy_to;
	ft_memmove(copy_to, copy_from + offset_y * window->settings.width, \
						(window->settings.height - offset_y) * \
							window->settings.width * sizeof(t_pixel_data));
}
