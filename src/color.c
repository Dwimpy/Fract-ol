/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:43:25 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 01:49:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/color.h"

static void	handle_rgb_region(t_rgb *rgb, t_hsv hsv, t_params p);

t_hsv	rgb_to_hsv(t_rgb rgb)
{
	double	max;
	double	min;
	double	d;
	t_hsv	hsv;

	max = get_max(rgb.r, rgb.g, rgb.b);
	min = get_min(rgb.r, rgb.g, rgb.b);
	hsv.v = max;
	hsv.s = 0;
	if (max != 0)
		hsv.s = (max - min) / max;
	hsv.h = -1;
	if (hsv.s != 0)
		d = max - min;
	if (rgb.r == max)
		hsv.h = (rgb.g - rgb.b) / d;
	else if (rgb.g == max)
		hsv.h = 2 + (rgb.b - rgb.r) / d;
	else if (rgb.b == max)
		hsv.h = 4 + (rgb.r - rgb.g) / d;
	hsv.h = 60 * hsv.h;
	if (hsv.h < 0)
		hsv.h += 360;
	return (hsv);
}

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	t_params		params;
	t_rgb			rgb;

	if (hsv.s == 0)
	{
		rgb.r = hsv.v;
		rgb.g = hsv.v;
		rgb.b = hsv.v;
		return (rgb);
	}
	else
	{
		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h /= 60;
		params.sextant = floorf(hsv.h);
		params.fract = hsv.h - params.sextant;
		params.p = hsv.v*(1 - hsv.s);
		params.q = hsv.v*(1 - (hsv.s * params.fract));
		params.t = hsv.v*(1 - (hsv.s *(1 - params.fract)));
	}
	handle_rgb_region(&rgb, hsv, params);
	return (rgb);
}

static void	handle_rgb_region(t_rgb *rgb, t_hsv hsv, t_params p)
{
	if (p.sextant == 0)
		set_rgb(rgb, hsv.v, p.t, p.p);
	else if (p.sextant == 1)
		set_rgb(rgb, p.q, hsv.v, p.p);
	else if (p.sextant == 2)
		set_rgb(rgb, p.p, hsv.v, p.t);
	else if (p.sextant == 3)
		set_rgb(rgb, p.p, p.q, hsv.v);
	else if (p.sextant == 4)
		set_rgb(rgb, p.t, p.p, hsv.v);
	else
		set_rgb(rgb, hsv.v, p.p, p.q);
}
