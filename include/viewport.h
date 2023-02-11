/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:40 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 16:10:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "../include/complex.h"
# include "../include/window.h"

typedef struct s_centers
{
	double		cx;
	double		cy;
}				t_centers;

typedef struct s_size
{
	uint32_t	width;
	uint32_t	height;
}				t_size;

typedef struct s_boundary
{
	double		x_min;
	double		y_max;
}				t_boundary;

typedef struct s_data
{
	t_complex	var;
	t_complex	constant;
}				t_data;

typedef struct s_viewport
{
	double			pixel_size;
	t_data			data;
	t_centers		centers;
	t_size			size;
	t_boundary		boundary;
}					t_viewport;

void	set_viewport_centers(t_viewport *viewport, \
								double center_x, \
									double center_y);
void	set_viewport_size(t_viewport *viewport, \
							uint32_t width, \
								uint32_t height);
void	set_viewport_boundary(t_viewport *viewport);
void	set_pixel_size(t_viewport *viewport, double pixel_size);
void	set_viewport_boundaries_zoom(t_viewport *viewport, \
										int32_t mouse_x, int32_t mouse_y);
#endif
