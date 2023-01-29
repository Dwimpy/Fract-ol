/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:52 by arobu             #+#    #+#             */
/*   Updated: 2023/01/29 02:01:56 by arobu            ###   ########.fr       */
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
void		*key_hooks(mlx_key_data_t keydata, t_program *data);
void		*resize_hooks(int32_t new_width, \
							int32_t new_height, \
								t_program *data);

#endif
