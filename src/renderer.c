/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 19:52:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../include/renderer.h"
#include "../include/color.h"

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

uint32_t	put_pixel_color(t_pixel_data *data, t_rgb color, double data_k)
{
	double	a;
	double	b;
	double	c;
	double	potential;
	double	k;

	a = 1.;
	b = 0.34004648219;
	c = 0.17965377284;
	k = (1. / sqrt(sqrt(data->distance))) * (data_k * data_k + 0.1);
	potential = data->potential / k;
	if (data->iteration.zone == OUTSIDE)
		return (get_rgba(((1 - cos(a * potential)) / 2) * color.r, \
						((1 - cos(b * potential)) / 2) * color.g, \
						((1 - cos(c * potential)) / 2) * color.b, \
						0xFF));
	if (data->iteration.zone == BOUNDARY)
		return (get_rgba((data->potential) * 167, \
						88, \
						213, \
						0xFF));
	return (get_rgba(0x0, 0x0, 0x0, 0xFF));
}
