/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:25:46 by arobu             #+#    #+#             */
/*   Updated: 2023/01/29 15:00:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

t_window	create_window(char *title, int resizeable)
{
	t_window	window;

	window.title = title;
	window.resize_flags = 0;
	set_window_settings(&window, resizeable);
	return (window);
}

void	resize_window(t_window *window, int32_t new_width, int32_t new_height)
{
	window->settings.width = new_width;
	window->settings.height = new_height;
}

t_w_corner	set_corner(int32_t x, int32_t y, t_orientation orientation)
{
	t_w_corner	corner;

	corner.x = x;
	corner.y = y;
	corner.orientation = orientation;
	return (corner);
}

void	set_window_settings(t_window *window, int resizeable)
{
	resize_window(window, W_WIDTH, W_HEIGHT);
	window->settings.is_resizeable = resizeable;
	window->settings.min_width = 1280;
	window->settings.max_width = 1920;
	window->settings.min_height = 720;
	window->settings.max_height = 1080;
}

void	set_corners(t_window *window, \
						mlx_t *context, \
							void (*f)(mlx_t *, int32_t *, int32_t *))
{
	f(context, &window->corners.top_left.x, &window->corners.top_left.y);
	window->corners.top_left.x = 0;
	window->corners.top_left.y = 0;
	window->corners.top_left.orientation = TOP_LEFT;
	window->corners.top_right = set_corner(window->corners.top_left.x + \
												window->settings.width, \
												window->corners.top_left.y, \
												TOP_RIGHT);
	window->corners.bottom_right = set_corner(window->corners.top_left.x + \
												window->settings.width, \
												window->corners.top_left.y + \
												window->settings.height, \
												BOTTOM_RIGHT);
	window->corners.bottom_left = set_corner(window->corners.top_left.x, \
												window->corners.top_left.y + \
												window->settings.height, \
												BOTTOM_RIGHT);
}