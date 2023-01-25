/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:49:39 by arobu             #+#    #+#             */
/*   Updated: 2023/01/25 20:36:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

void	render_window(t_renderer *renderer, t_bg_color bg_color)
{
	t_window	window;

	window = create_window(W_WIDTH, W_HEIGHT, W_TITLE, W_RESIZEABLE);
	window.bg_color = set_window_background(bg_color);
	renderer->mlx = mlx_init(window.width, window.height, \
								window.title, window.is_resizeable);
	if (!renderer->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	set_background(renderer, window);
}

void	rendering_loop(t_renderer *renderer)
{
	mlx_loop(renderer->mlx);
	mlx_terminate(renderer->mlx);
}

void	set_background(t_renderer *renderer, t_window window)
{
	renderer->background = mlx_new_image(renderer->mlx, \
											window.width, \
												window.height);
	ft_memset(renderer->background->pixels, window.bg_color, \
				renderer->background->width \
					* renderer->background->height \
						* sizeof(int));
	mlx_image_to_window(renderer->mlx, renderer->background, 0, 0);
}