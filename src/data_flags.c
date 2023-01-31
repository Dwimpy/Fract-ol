/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:28:19 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 15:13:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	update_flags_on_press(t_program *data, \
								action_t action, \
									t_dir dir_flags)
{
	if (action == MLX_PRESS)
		data->controller_flag |= dir_flags;
}

static void	update_flags_on_release(t_program *data, \
									action_t action, \
										t_dir dir_flags)
{
	if (action == MLX_RELEASE)
		data->controller_flag &= ~dir_flags;
}

void	update_direction(t_program *data, \
							action_t action, \
								t_dir dir_flags)
{
	if (action == MLX_PRESS)
		update_flags_on_press(data, action, dir_flags);
	else if (action == MLX_RELEASE)
		update_flags_on_release(data, action, dir_flags);
}