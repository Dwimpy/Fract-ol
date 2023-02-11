/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:38 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 21:27:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <stdlib.h>
# include <math.h>

typedef struct s_rgb
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}		t_rgb;

void	set_rgb(t_rgb *rgb, double r, double g, double b);
int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a);

#endif
