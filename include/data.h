/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:52 by arobu             #+#    #+#             */
/*   Updated: 2023/01/30 16:41:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "renderer.h"

typedef struct s_program
{
	t_fractals		*fractals;
	t_renderer		renderer;
	t_window		window;
	uint8_t			translation;
}					t_program;

t_program	set_program(t_renderer *renderer, \
							t_fractals *fractals, \
								t_window *window);
void		key_hooks(mlx_key_data_t keydata, t_program *data);
void		resize_hooks(int32_t new_width, \
							int32_t new_height, \
								t_program *data);
void		translate_right(t_program *data, uint32_t offset);
void		translate_left(t_program *data, uint32_t offset);
void		translate_up(t_program *data, uint32_t offset);
void		translate_down(t_program *data, uint32_t offset);

void		render_fractal_horizontal(t_program *data, \
										int32_t start_pixel, \
											int32_t offset_x);
void		render_known_right(t_program *data, uint32_t offset_x);
void		render_known_left(t_program *data, uint32_t offset_x);

#endif
