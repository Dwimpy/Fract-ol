/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:25:46 by arobu             #+#    #+#             */
/*   Updated: 2023/01/24 22:13:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"
#include "../libft/include/libft.h"

t_window	create_window(int width, int height, \
							char *title, t_bg_color bg_color)
{
	t_window	window;
	mlx_image_t	*new_image;

	window.width = width;
	window.height = height;
	window.title = title;
	window.mlx = mlx_init(window.width, window.height, \
						window.title, DEFAULT_RESIZE_OPTION);
	if (!window.mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	set_window_backgroud(&window, bg_color);
	return (window);
}

void	set_window_backgroud(t_window *window, t_bg_color bg_color)
{

	window->background = mlx_new_image(window->mlx, \
										window->width, \
											window->height);
	if (bg_color == BLACK)
		ft_memset(window->background->pixels, BG_COLOR_BLACK, \
					window->background->width \
						* window->background->height \
							* sizeof(int));
	else if (bg_color == WHITE)
		ft_memset(window->background->pixels, BG_COLOR_WHITE, \
					window->background->width \
						* window->background->height \
							* sizeof(int));
	mlx_image_to_window(window->mlx, window->background, 0, 0);
}

void	window_loop(t_window *window)
{
	mlx_loop(window->mlx);
	mlx_terminate(window->mlx);
}