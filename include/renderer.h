/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:28:32 by arobu             #+#    #+#             */
/*   Updated: 2023/01/25 20:36:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "renderer.h"
# include "window.h"

typedef struct s_renderer
{
	mlx_t		*mlx;
	mlx_image_t	*background;
}				t_renderer;

void		set_background(t_renderer *renderer, t_window window);
void		render_window(t_renderer *renderer, t_bg_color bg_color);
void		rendering_loop(t_renderer *renderer);

#endif