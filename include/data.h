/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:52 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 17:36:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "renderer.h"
# include "color.h"

typedef void	(*t_fractal_eq)(double pixel_size, t_complex *var, \
					t_complex *constant, t_pixel_data *pixel_map);

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

typedef struct s_arg_opts
{
	bool		mandelbrot;
	bool		julia;
	bool		tricorn;
	bool		is_animated;
	t_rgb		color;
	t_complex	var;
	bool		is_redrawing;
}				t_arg_opts;

typedef struct s_program
{
	t_fractals		*fractals;
	t_renderer		renderer;
	t_window		window;
	t_mouse_pos		mouse;
	t_pixel_data	*pixel_map;
	t_arg_opts		args;
	t_fractal_eq	equation;
	double			k;
	uint8_t			controller_flag;
}					t_program;

void			key_hooks(mlx_key_data_t keydata, t_program *data);
void			init_args(t_arg_opts *args);
void			check_julia_args(char *str);
void			swap_fractal(t_program *data, action_t action, int key);
void			fractol_usage(char *err_msg);
char			*get_arg_string(char **argv);
void			get_color_args(char **argv, t_arg_opts *args);
void			resize_hooks(int32_t new_width, int32_t new_height, \
							t_program *data);
void			movement_hook(t_program *data);
void			handle_movement(t_program *data);
void			scroll_hook(double xdelta, double ydelta, t_program *data);
void			redraw_julia(t_program *data);
void			translate_viewport(t_program *data, \
							int32_t offset, t_dir direction);
void			render_translation(t_program *data, \
							int32_t offset, t_dir direction);
void			handle_keys(t_program *data, action_t action, int key);
void			zoom(t_program *data, double ydelta, double scale);
void			initialize_fractal(t_program *data);
void			create_fractal_image(t_renderer *renderer, \
							t_fractal_node **fractal, \
							bool (*has_image)(t_fractal_node *fractal));
void			render_viewport(t_program *data, t_render_iter	iter, \
							t_render_enum type);
void			init_behavior(t_program *data, \
						t_render_iter *iter, t_render_enum type);
void			render_and_translate(t_program *data, int32_t offset, \
								t_render_iter iter, t_dir direction);
t_render_iter	set_offset(uint32_t from_col, uint32_t from_row, \
							uint32_t to_col, uint32_t to_row);

void			init_julia(t_program *data, t_render_iter *iter, \
							int32_t *start_col);
t_pixel_data	*init_pixel_map(void);
void			animate(t_program *data);
void			anim_translation(t_program *data, \
				int32_t offset, t_dir direction);

#endif
