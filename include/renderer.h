/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:28:32 by arobu             #+#    #+#             */
/*   Updated: 2023/01/29 19:25:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "window.h"
# include "viewport.h"
# include "fractals.h"

typedef struct s_renderer
{
	mlx_t		*mlx;
}				t_renderer;

t_window	render_window(t_renderer *renderer);
void		render_fractal_viewport(t_renderer *renderer, \
									t_fractal_node *fractal, \
										t_window window, \
											t_fractal_name name);
void		create_fractal_image(t_renderer **renderer, \
									t_fractal_node **fractal, \
									bool (*has_image)(t_fractal_node *fractal));
void		rendering_loop(t_renderer *renderer);



#endif