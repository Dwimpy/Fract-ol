/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:30:48 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 19:01:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	animate(t_program *data)
{
	uint32_t	i;
	uint32_t	j;
	t_viewport	*vp;

	vp = &data->fractals->front->viewport;
	j = -1;
	data->k = fabs(sin((mlx_get_time()) * 0.5f)) * 4.;
	while (++j < vp->size.height)
	{
		i = -1;
		while (++i < vp->size.width)
		{
			mlx_put_pixel(data->fractals->front->image, i, j, \
			put_pixel_color(&data->pixel_map[j * vp->size.width + i], \
							data->args.color, data->k));
		}
	}
}
