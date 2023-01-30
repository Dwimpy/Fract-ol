/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/01/30 01:56:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

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

	create_fractal_image(&renderer, &fractal, &has_image);
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

void	create_fractal_image(t_renderer **renderer, \
								t_fractal_node **fractal, \
									bool (*has_image)(t_fractal_node *fractal))
{
	if (has_image(*fractal) == false)
	{
		(*fractal)->image = mlx_new_image((*renderer)->mlx, \
											W_WIDTH, \
												W_HEIGHT);
		if (!fractal)
		{
			ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
			exit(EXIT_FAILURE);
		}
		mlx_image_to_window((*renderer)->mlx, (*fractal)->image, 0, 0);
		(*fractal)->has_image = true;
	}
}