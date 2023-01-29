/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:18:51 by arobu             #+#    #+#             */
/*   Updated: 2023/01/28 18:46:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

t_fractal_node	*create_fractal(t_fractal_name name)
{
	t_fractal_node	*new_fractal;

	initialize_fractal(&new_fractal, name);
	new_fractal->image = NULL;
	new_fractal->next = NULL;
	new_fractal->prev = NULL;
	new_fractal->has_image = false;
	return (new_fractal);
}

void	initialize_fractal(t_fractal_node **fractal, t_fractal_name name)
{
	(*fractal) = (t_fractal_node *)malloc(sizeof(t_fractal_node));
	if (name == MANDELBROT)
		initialize_mandelbrot(fractal);
}

void	initialize_mandelbrot(t_fractal_node **fractal)
{
	t_viewport	*viewport;

	viewport = &(*fractal)->viewport;
	set_pixel_size(viewport, 0.001);
	set_viewport_centers(viewport, -1.4, 0);
	set_viewport_size(viewport, W_WIDTH, W_HEIGHT);
	set_viewport_boundary(viewport);
}

bool	has_image(t_fractal_node *fractal)
{
	return (fractal->has_image == true);
}