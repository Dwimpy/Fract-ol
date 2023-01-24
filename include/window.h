/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:05:36 by arobu             #+#    #+#             */
/*   Updated: 2023/01/24 22:14:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define DEFAULT_RESIZE_OPTION 1
# define BG_COLOR_BLACK 0
# define BG_COLOR_WHITE 255
# include "../MLX42/include/MLX42/MLX42.h"

typedef enum e_bg_color
{
	BLACK = 0,
	WHITE = 1
}			t_bg_color;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*background;
	int			width;
	int			height;
	char		*title;
}				t_window;

t_window	create_window(int width, int height, \
							char *title, t_bg_color bg_color);
void		set_window_backgroud(t_window *window, t_bg_color bg_color);
void		window_loop(t_window *window);
#endif