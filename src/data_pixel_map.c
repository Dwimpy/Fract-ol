/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_pixel_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:38:54 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 21:46:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

t_pixel_data	*init_pixel_map(void)
{
	t_pixel_data	*pixel_map;

	pixel_map = (t_pixel_data *)malloc(sizeof(t_pixel_data) * \
											1920 * 1080);
	if (!pixel_map)
		return (NULL);
	pixel_map->k = 1.;
	pixel_map->distance = 0;
	pixel_map->potential = 0;
	pixel_map->iteration.iteration = 0;
	return (pixel_map);
}

