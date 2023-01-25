/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:40 by arobu             #+#    #+#             */
/*   Updated: 2023/01/25 20:20:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "../include/complex.h"

typedef struct s_vp_axis_range
{
	int			min_range;
	int			max_range;
}				t_vp_axis_range;

typedef struct s_vp_bounds
{
	t_vp_axis_range	x_range;
	t_vp_axis_range	y_range;
}				t_vp_bounds;

typedef struct s_viewport
{
	t_complex	data;
	t_vp_bounds	bounds;
}				t_viewport;

#endif