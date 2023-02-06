/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:24:36 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 16:25:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	initialize_mandelbrot(t_program *data, \
								t_fractal_node **fractal);
static void	initialize_julia(t_program *data, \
								t_fractal_node **fractal, \
									t_complex c);

void	initialize_fractal(t_program *data, \
							t_fractal_name name, \
							t_complex c)
{
	if (name == MANDELBROT)
		initialize_mandelbrot(data, &data->fractals->front);
	else if (name == JULIA)
		initialize_julia(data, &data->fractals->front, c);
}

static void	initialize_mandelbrot(t_program *data, \
								t_fractal_node **fractal)
{
	t_viewport	*viewport;
	t_window	*window;

	create_fractal_image(&data->renderer, fractal, has_image);
	window = &data->window;
	viewport = &(*fractal)->viewport;
	(*fractal)->name = MANDELBROT;
	set_pixel_size(viewport, 0.0024);
	set_viewport_centers(viewport, -1.4, 0);
	set_viewport_size(viewport, \
						window->settings.width, \
							window->settings.height);
	set_viewport_boundary(viewport);
}

static void	initialize_julia(t_program *data, \
							t_fractal_node **fractal, \
								t_complex c)
{
	t_viewport	*viewport;
	t_window	*window;

	create_fractal_image(&data->renderer, fractal, has_image);
	window = &data->window;
	viewport = &(*fractal)->viewport;
	(*fractal)->name = JULIA;
	(*fractal)->viewport.data.c = c;
	set_pixel_size(viewport, 0.001);
	set_viewport_centers(viewport, 0, 0);
	set_viewport_size(viewport, \
						window->settings.width, \
							window->settings.height);
	set_viewport_boundary(viewport);
}

void	create_fractal_image(t_renderer *renderer, \
								t_fractal_node **fractal, \
									bool (*has_image)(t_fractal_node *fractal))
{
	if (has_image(*fractal) == false)
	{
		(*fractal)->image = mlx_new_image((renderer)->mlx, \
											W_WIDTH, \
												W_HEIGHT);
		if (!fractal)
		{
			ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
			exit(EXIT_FAILURE);
		}
		mlx_image_to_window((renderer)->mlx, (*fractal)->image, 0, 0);
		(*fractal)->has_image = true;
	}
}
