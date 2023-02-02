/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:18:51 by arobu             #+#    #+#             */
/*   Updated: 2023/02/02 20:27:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

t_fractal_node	*create_fractal(t_window *window, t_fractal_name name)
{
	t_fractal_node	*new_fractal;

	new_fractal = NULL;
	initialize_fractal(&new_fractal, window, name);
	new_fractal->image = NULL;
	new_fractal->next = NULL;
	new_fractal->prev = NULL;
	new_fractal->has_image = false;
	return (new_fractal);
}

void	initialize_fractal(t_fractal_node **fractal, \
								t_window *window, \
									t_fractal_name name)
{
	if ((*fractal) == NULL)
		(*fractal) = (t_fractal_node *)malloc(sizeof(t_fractal_node));
	if (name == MANDELBROT)
		initialize_mandelbrot(fractal, window);
}

void	initialize_mandelbrot(t_fractal_node **fractal, t_window *window)
{
	t_viewport	*viewport;

	viewport = &(*fractal)->viewport;
	set_pixel_size(viewport, 0.0024);
	set_viewport_centers(viewport, -0.8, 0);
	set_viewport_size(viewport, \
						window->settings.width, \
							window->settings.height);
	set_viewport_boundary(viewport);
}

bool	has_image(t_fractal_node *fractal)
{
	return (fractal->has_image == true);
}
