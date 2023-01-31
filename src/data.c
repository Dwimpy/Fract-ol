/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:37:18 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 17:40:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	move_right(t_program *data, t_dir dir)
{
	translate_right(data, 20);
	render_known_right(data, 20);
	render_fractal_horizontal(data, data->window.settings.width - 20, 20);
}

void	move_left(t_program *data, t_dir dir)
{
	translate_left(data, 20);
	render_known_left(data, 20);
	render_fractal_horizontal(data, 0, 20);
}

void	move_up(t_program *data, t_dir dir)
{
	translate_up(data, 20);
	render_known_up(data, 20);
	render_fractal_vertical(data, 0, 20, 0);
}

void	move_down(t_program *data, t_dir dir)
{
	translate_down(data, 20);
	render_known_down(data, 20);
	render_fractal_vertical(data, data->window.settings.height - 20, \
								data->window.settings.height, \
								data->window.settings.height - 20);
}