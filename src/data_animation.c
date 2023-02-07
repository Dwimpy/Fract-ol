/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:30:48 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 03:08:20 by arobu            ###   ########.fr       */
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
	printf("%f", mlx_get_time());
	while (++j < vp->size.height)
	{
		i = -1;
		while (++i < vp->size.width)
		{
			data->pixel_map[j * vp->size.width + i].k = \
				1 + fabs(cos((mlx_get_time()) * .3f)) * 30.;
			mlx_put_pixel(data->fractals->front->image, i, j, \
			put_pixel_color(&data->pixel_map[j * vp->size.width + i]));
		}
	}
}
