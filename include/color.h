/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:38 by arobu             #+#    #+#             */
/*   Updated: 2023/02/02 18:16:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <stdlib.h>
# include <math.h>

typedef struct s_params
{
	int		sextant;
	double	fract;
	double	p;
	double	q;
	double	t;
}		t_params;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}		t_rgb;

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;
}		t_hsv;

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a);
double	get_max(double r, double g, double b);
double	get_min(double r, double g, double b);
t_hsv	rgb_to_hsv(t_rgb rgb);
t_rgb	hsv_to_rgb(t_hsv hsv);
void	set_rgb(t_rgb *rgb, double r, double g, double b);

#endif
