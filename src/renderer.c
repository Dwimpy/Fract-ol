/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 01:53:36 by arobu            ###   ########.fr       */
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
	double	a;
	double	b;
	double	c;
	t_rgb	rgb;

	a = 1.;
	b = 0.34004648219;
	c = 0.17965377284;
	if (iteration.zone == OUTSIDE)
		return (get_rgba(((1 - cos(a * iteration.value)) / 2) * 200, \
						((1 - cos(b * iteration.value)) / 2) * 155, \
						((1 - cos(c * iteration.value)) / 2) * 77, \
						0xFF));
	if (iteration.zone == BOUNDARY)
		return (get_rgba((iteration.value) * 188, \
						155, \
						255, \
						0xFF));
	return (get_rgba(0x0, 0x0, 0x0, 0xFF));
}
