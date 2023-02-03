/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:44:13 by arobu             #+#    #+#             */
/*   Updated: 2023/02/03 13:43:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H
# define MAX_DEPTH 200
# define THICKNESS 0.006
# define RADIUS 10000
// # define BOUNDARY -1.0
// # define NOT_ENOUGH -2.0
// # define OUTSIDE -3.0
# include <stdbool.h>
# include "viewport.h"
# include "../MLX42/include/MLX42/MLX42.h"

/*
######################################
#     Fractals Interface Manager     #
######################################
#  Handles the creation and removal  #
#  of fractals from the fractal list #
######################################
*/

typedef struct s_fractal_node	t_fractal_node;

typedef enum e_fractal_name
{
	MANDELBROT,
	JULIA
}				t_fractal_name;

typedef enum e_fractal_zone
{
	INSET,
	BOUNDARY,
	OUTSIDE
}				t_fractal_zone;

typedef struct s_iteration
{
	unsigned int	iteration;
	t_fractal_zone	zone;
	double			value;
}					t_iteration;

typedef struct s_fractal_node
{
	t_fractal_name	name;
	t_viewport		viewport;
	mlx_image_t		*image;
	t_fractal_node	*next;
	t_fractal_node	*prev;
	bool			has_image;
}				t_fractal_node;

typedef struct s_fractals
{
	unsigned int	size;
	t_fractal_node	*front;
	t_fractal_node	*rear;
}				t_fractals;

/*
######################################
#       Fractals list handling       #
######################################
*/

void			create_fractal_stack(t_fractals **fractals);
int				is_stack_empty(t_fractals *fractals);
void			add_new_fractal(t_fractals **fractals);
t_iteration		distance_estimation(double pixel_size, \
										t_complex *z, \
											t_complex *c);

/*
######################################
#       Fractal nodes handling       #
######################################
*/

t_fractal_node	*create_empty_fractal(void);
void			destroy_fractal(t_fractals **fractals, \
								t_fractal_node *fractal);
bool			has_image(t_fractal_node *fractal);
#endif
