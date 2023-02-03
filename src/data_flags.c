/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:28:19 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 20:29:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	update_press(t_program *data, action_t action, t_dir dir_flags);
static void	update_release(t_program *data, action_t action, t_dir dir_flags);
static void	update_direction(t_program *data, action_t action, t_dir dir_flags);

void	handle_keys(t_program *data, action_t action, int key)
{
	if (key == MLX_KEY_ESCAPE && action == MLX_PRESS)
		mlx_close_window(data->renderer.mlx);
	else if (key == MLX_KEY_RIGHT && (action == MLX_PRESS || \
										action == MLX_RELEASE))
		update_direction(data, action, RIGHT);
	else if (key == MLX_KEY_LEFT && (action == MLX_PRESS || \
										action == MLX_RELEASE))
		update_direction(data, action, LEFT);
	else if (key == MLX_KEY_UP && (action == MLX_PRESS || \
										action == MLX_RELEASE))
		update_direction(data, action, UP);
	else if (key == MLX_KEY_DOWN && (action == MLX_PRESS || \
										action == MLX_RELEASE))
		update_direction(data, action, DOWN);
}

static void	update_press(t_program *data, action_t action, t_dir dir_flags)
{
	if (action == MLX_PRESS)
		data->controller_flag |= dir_flags;
}

static void	update_release(t_program *data, action_t action, t_dir dir_flags)
{
	if (action == MLX_RELEASE)
		data->controller_flag &= ~dir_flags;
}

static void	update_direction(t_program *data, action_t action, t_dir dir_flags)
{
	if (action == MLX_PRESS)
		update_press(data, action, dir_flags);
	else if (action == MLX_RELEASE)
		update_release(data, action, dir_flags);
}
