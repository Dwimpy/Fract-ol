/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:28:32 by arobu             #+#    #+#             */
/*   Updated: 2023/02/06 19:49:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "window.h"
# include "fractals.h"

typedef enum s_render_enum
{
	DEFAULT = 0,
	CUSTOM = 1
}				t_render_enum;

typedef struct s_render_iter
{
	int32_t		from_row;
	int32_t		to_row;
	int32_t		from_col;
	int32_t		to_col;
}			t_render_iter;

typedef struct s_renderer
{
	mlx_t		*mlx;
}				t_renderer;

t_window	render_window(t_renderer *renderer);
uint32_t	put_pixel_color(t_pixel_data *data);
#endif
