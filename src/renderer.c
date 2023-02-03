/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 04:31:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../include/renderer.h"
#include "../include/color.h"

static uint32_t	put_pixel_color(t_iteration iteration);

t_window	render_window(t_renderer *renderer)
{
	t_window	window;

	window = create_window(W_TITLE, W_RESIZEABLE);
	renderer->mlx = mlx_init(window.settings.width, window.settings.height, \
								window.title, window.settings.is_resizeable);
	if (!renderer->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	mlx_set_window_limit(renderer->mlx, window.settings.min_width, \
											window.settings.min_height, \
												window.settings.max_width, \
													window.settings.max_height);
	set_corners(&window, renderer->mlx, &mlx_get_window_pos);
	return (window);
}


void	render_fractal_viewport(t_renderer *renderer, \
									t_fractal_node *fractal, \
										t_window window,
											t_fractal_name name)
{
	int			i;
	int			j;
	t_iteration	iteration;
	t_viewport	*viewport;

	viewport = &fractal->viewport;
	i = -1;
	viewport->data.c.imag = viewport->boundary.y_max;
	while (++i < viewport->size.height)
	{
		j = -1;
		viewport->data.c.real = viewport->boundary.x_min;
		while (++j < viewport->size.width)
		{
			iteration = distance_estimation(viewport->pixel_size, \
												&viewport->data.z, \
													&viewport->data.c);
			mlx_put_pixel(fractal->image, j, i, put_pixel_color(iteration));
			viewport->data.c.real += viewport->pixel_size;
		}
		viewport->data.c.imag -= viewport->pixel_size;
	}
}

static uint32_t	put_pixel_color(t_iteration iteration)
{
	double	smooth;
	t_rgb	rgb;

	smooth = (iteration.iteration / MAX_DEPTH + 1 - iteration.value);
	rgb = hsv_to_rgb((t_hsv){359 * iteration.iteration / MAX_DEPTH, \
							0.7f, .86f});
	if (iteration.zone == OUTSIDE)
		return (get_rgba(rgb.r * fabs(sin(sinh(iteration.value))) * 45, \
						rgb.g * 12, \
						rgb.b * fabs(sin(sinh(iteration.value))) *255, \
						0xFF));
	else if (iteration.zone == BOUNDARY)
		return (get_rgba(rgb.r * fabs(cosh(iteration.value)) * 177, \
						rgb.g * 166, \
						rgb.b * 199, \
						0xFF));
	return (get_rgba(0x0, 0x0, 0x0, 0xFF));
}

void	render_viewport(t_renderer *renderer, \
									t_fractal_node *fractal, \
										t_window window)
{
	int			i;
	int			j;
	t_iteration	iteration;

	i = -1;
	fractal->viewport.data.c.imag = fractal->viewport.boundary.y_max;
	while (++i < window.settings.height)
	{
		j = -1;
		fractal->viewport.data.c.real = fractal->viewport.boundary.x_min;
		while (++j < window.settings.width)
		{
			iteration = distance_estimation(fractal->viewport.pixel_size, \
												&fractal->viewport.data.z, \
													&fractal->viewport.data.c);
			if (iteration.zone == BOUNDARY)
				mlx_put_pixel(fractal->image, j, i, 0x0000FFFF);
			else if (iteration.zone == OUTSIDE)
				mlx_put_pixel(fractal->image, j, i, 0xFF00003a);
			else
				mlx_put_pixel(fractal->image, j, i, 0x000000FF);
			fractal->viewport.data.c.real += fractal->viewport.pixel_size;
		}
		fractal->viewport.data.c.imag -= fractal->viewport.pixel_size;
	}
}

void	renderer_put_pixels(t_renderer **renderer, \
								mlx_image_t **image, \
									t_iteration iteration)
{

}


