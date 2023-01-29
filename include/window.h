/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:05:36 by arobu             #+#    #+#             */
/*   Updated: 2023/01/29 19:28:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define DEFAULT_RESIZE_OPTION 1
# define W_WIDTH 1280
# define W_HEIGHT 760
# define W_TITLE "Fract-ol"
# define W_RESIZEABLE 1
# define UP 0x1
# define RIGHT 0x2
# define DOWN 0x4
# define LEFT 0x8

# include "../MLX42/include/MLX42/MLX42.h"

typedef enum e_orientation
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_RIGHT,
	BOTTOM_LEFT,
}			t_orientation;

typedef struct s_w_corner
{
	int32_t			x;
	int32_t			y;
	t_orientation	orientation;
}				t_w_corner;

typedef struct s_corners
{
	t_w_corner	top_left;
	t_w_corner	top_right;
	t_w_corner	bottom_right;
	t_w_corner	bottom_left;
}				t_corners;

typedef struct s_screen_left
{
	int32_t		screen_x;
	int32_t		screen_y;
}				t_screen_left;

typedef struct s_window_settings
{
	int32_t		width;
	int32_t		height;
	int			is_resizeable;
	int			min_width;
	int			min_height;
	int			max_width;
	int			max_height;
}				t_window_settings;

typedef struct s_window
{
	char				*title;
	unsigned int		resize_flags;
	t_window_settings	settings;
	t_corners			corners;
	t_screen_left		screen_coords;
}						t_window;

t_window	create_window(char *title, int isresizeable);
void		resize_window(t_window *window, \
							int32_t new_width, \
								int32_t new_height);
void		set_corners(t_window *window, \
							mlx_t *context, \
								void (*f)(mlx_t *, int32_t *, int32_t *));
void		set_window_settings(t_window *window, int resizeable);
t_w_corner	set_corner(int32_t x, int32_t y, t_orientation orientation);

#endif