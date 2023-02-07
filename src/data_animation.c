/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:30:48 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 14:01:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

void	animate(t_program *data)
{
	uint32_t	row_index;
	uint32_t	i;
	uint32_t	j;
	t_viewport	*vp;
	uint32_t	pixel_row;

	vp = &data->fractals->front->viewport;
	j = -1;
	while (++j < vp->size.height)
	{
		i = -1;
		while (++i < vp->size.width)
		{
			data->pixel_map[j * vp->size.width + i].k = \
				fabs(sin((mlx_get_time()) * 0.5f)) * 3.;
			mlx_put_pixel(data->fractals->front->image, i, j, \
			put_pixel_color(&data->pixel_map[j * vp->size.width + i]));
		}
	}
}
