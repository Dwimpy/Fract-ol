/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:44:13 by arobu             #+#    #+#             */
/*   Updated: 2023/01/31 02:55:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H
# define MAX_DEPTH 100
# define THICKNESS 0.005
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

t_fractals		*create_fractal_stack(void);
int				is_stack_empty(t_fractals *fractals);
void			add_new_fractal(t_fractals **fractals, \
									t_window *window, \
										t_fractal_name name);
t_iteration		distance_estimation(double pixel_size, \
										t_complex *z, \
											t_complex *c);

/*
######################################
#       Fractal nodes handling       #
######################################
*/

t_fractal_node	*create_fractal(t_window *window, t_fractal_name name);
void			initialize_fractal(t_fractal_node **fractal, \
										t_window *window, \
											t_fractal_name name);
void			initialize_mandelbrot(t_fractal_node **fractal, t_window *window);
bool			has_image(t_fractal_node *fractal);

#endif
