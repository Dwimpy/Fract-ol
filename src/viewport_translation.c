/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_translation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:15:52 by arobu             #+#    #+#             */
/*   Updated: 2023/01/30 16:46:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	translate_right(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cx += viewport->pixel_size * offset;
	set_viewport_boundary(viewport);
}

void	translate_left(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cx -= viewport->pixel_size * offset;
	set_viewport_boundary(viewport);
}

void	translate_up(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cy += viewport->pixel_size * offset;
}

void	translate_down(t_program *data, uint32_t offset)
{
	t_viewport	*viewport;

	viewport = &data->fractals->front->viewport;
	viewport->centers.cy -= viewport->pixel_size * offset;
}