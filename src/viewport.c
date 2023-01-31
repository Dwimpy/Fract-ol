/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:19:45 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 21:26:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/viewport.h"
#include "../include/window.h"

void	set_pixel_size(t_viewport *viewport, double pixel_size)
{
	viewport->pixel_size = pixel_size;
}

void	set_viewport_centers(t_viewport *viewport, \
								double center_x, \
									double center_y)
{
	viewport->centers.cx = center_x;
	viewport->centers.cy = center_y;
}

void	set_viewport_size(t_viewport *viewport, \
							uint32_t width, \
								uint32_t height)
{
	viewport->size.width = width;
	viewport->size.height = height;
}

void	set_viewport_boundary(t_viewport *viewport)
{
	viewport->boundary.x_min = viewport->centers.cx \
								- viewport->pixel_size \
									* (viewport->size.width / 2.0001);
	viewport->boundary.y_max = viewport->centers.cy \
								+ viewport->pixel_size \
									* (viewport->size.height / 2.0001);
}

void	set_viewport_boundaries_zoom(t_viewport *viewport, int32_t mouse_x, int32_t mouse_y)
{
	viewport->boundary.x_min = viewport->centers.cx - \
								viewport->pixel_size * mouse_x;
	viewport->boundary.y_max = viewport->centers.cy + \
								viewport->pixel_size * mouse_y;
	fflush(stdout);
}