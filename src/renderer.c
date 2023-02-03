/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 22:52:19 by arobu            ###   ########.fr       */
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

uint32_t	put_pixel_color(t_iteration iteration)
{
	double	smooth;
	t_rgb	rgb;
	t_hsv	hsv;

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
