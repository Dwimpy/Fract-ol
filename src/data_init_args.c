/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:44:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 16:47:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	init_args(t_arg_opts *args)
{
	args->mandelbrot = false;
	args->julia = false;
	args->burning_ship = false;
	args->is_animated = true;
	args->color = (t_rgb){255, 255, 255};
	set_complex(&args->var, -0.73, 0.18);
}

