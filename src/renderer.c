/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 03:07:08 by arobu            ###   ########.fr       */
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

uint32_t	put_pixel_color(t_pixel_data *data)
{
	double	a;
	double	b;
	double	c;
	double	potential;
	double	k;

	a = 1.;
	b = 0.34004648219;
	c = 0.17965377284;
	k = (1. / sqrt(data->distance)) * (data->k * data->k);
	potential = data->potential / k;
	if (data->iteration.zone == OUTSIDE)
		return (get_rgba(((1 - cos(a * potential)) / 2) * 255, \
						((1 - cos(b * potential)) / 2) * 255, \
						((1 - cos(c * potential)) / 2) * 255, \
						0xFF));
	if (data->iteration.zone == BOUNDARY)
		return (get_rgba((data->potential) * 188, \
						155, \
						255, \
						0xFF));
	return (get_rgba(0x0, 0x0, 0x0, 0xFF));
}

// double	distance(double z_mag_sq, t_complex dz, double power)
// {
// 	double	distance;
// 	double	k;

// 	distance = log(z_mag_sq) * 0.5f * \
// 		sqrt(z_mag_sq / mag_squared(dz.real, dz.imag));
// 	k = fabs(sin(3.1415)) * 3.f;
// 	k = (1./sqrt(distance)) * (k * k + .25f);
// 	return (log(log(z_mag_sq) / power) * k);
// }
