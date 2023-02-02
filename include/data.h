/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:52 by arobu             #+#    #+#             */
/*   Updated: 2023/02/02 15:47:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "renderer.h"
# include "color.h"

typedef enum e_dir
{
	UP = 0x1,
	RIGHT = 0x2,
	DOWN = 0x4,
	LEFT = 0x8
}			t_dir;

typedef struct mouse_pos
{
	int			x;
	int			y;
}				t_mouse_pos;

typedef struct s_program
{
	t_fractals		*fractals;
	t_renderer		renderer;
	t_window		window;
	t_mouse_pos		mouse;
	uint8_t			controller_flag;
}					t_program;

t_program	set_program(t_renderer *renderer, \
							t_fractals *fractals, \
								t_window *window);
void		key_hooks(mlx_key_data_t keydata, t_program *data);
void		resize_hooks(int32_t new_width, \
							int32_t new_height, \
								t_program *data);
void		movement_hook(t_program *data);
void		scroll_hook(double xdelta, double ydelta, t_program *data);

void		translate_right(t_program *data, uint32_t offset);
void		translate_left(t_program *data, uint32_t offset);
void		translate_up(t_program *data, uint32_t offset);
void		translate_down(t_program *data, uint32_t offset);

void		render_fractal_horizontal(t_program *data, \
										int32_t start_pixel, \
											int32_t offset_x);
void		render_fractal_vertical(t_program *data, \
										int32_t from_row, \
											int32_t to_row, \
												int32_t cx_offset);
void		render_viewport(t_renderer *renderer, \
									t_fractal_node *fractal, \
										t_window window);
void		render_known_right(t_program *data, uint32_t offset_x);
void		render_known_left(t_program *data, uint32_t offset_x);
void		render_known_up(t_program *data, uint32_t offset_y);
void		render_known_down(t_program *data, uint32_t offset_y);
void		update_direction(t_program *data, \
								action_t action, \
									t_dir dir_flags);
void		move_right(t_program *data, t_dir dir);
void		move_left(t_program *data, t_dir dir);
void		move_up(t_program *data, t_dir dir);
void		move_down(t_program *data, t_dir dir);
void		zoom(t_program *data, double ydelta, double scale);

#endif
