/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:13:43 by arobu             #+#    #+#             */
/*   Updated: 2023/02/02 18:15:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/color.h"

double	get_max(double r, double g, double b)
{
	double	max;

	max = 0;
	if (r > max)
		max = r;
	if (g > max)
		max = g;
	if (b > max)
		max = b;
	return (max);
}

double	get_min(double r, double g, double b)
{
	double	min;

	min = 1;
	if (r < min)
		min = r;
	if (g < min)
		min = g;
	if (b < min)
		min = b;
	return (min);
}

void	set_rgb(t_rgb *rgb, double r, double g, double b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
