/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:40 by arobu             #+#    #+#             */
/*   Updated: 2023/01/23 13:55:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include "../include/complex.h"

typedef struct s_grid_point
{
	t_complex		data;
}					t_grid_point;

typedef struct s_grid_axis
{
	float			min_range;
	float			max_range;
}					t_grid_axis;

typedef struct s_grid_axes
{
	t_grid_axis		x_axis;
	t_grid_axis		y_axis;
}					t_grid_axes;

typedef struct s_grid
{
	int				rows;
	int				cols;
	t_grid_axes		axes;
	t_grid_point	**grid;
}					t_grid;

#endif