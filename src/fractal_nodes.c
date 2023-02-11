/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:18:51 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 18:26:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

t_fractal_node	*create_empty_fractal(void)
{
	t_fractal_node	*new_fractal;

	new_fractal = (t_fractal_node *)malloc(sizeof(t_fractal_node));
	new_fractal->image = NULL;
	new_fractal->next = NULL;
	new_fractal->prev = NULL;
	new_fractal->has_image = false;
	return (new_fractal);
}

bool	has_image(t_fractal_node *fractal)
{
	return (fractal->has_image == true);
}

void	*destroy_node(mlx_t *mlx, t_fractal_node **node)
{
	if ((*node)->has_image == true)
		mlx_delete_image(mlx, (*node)->image);
	free(*node);
	*node = NULL;
	return (NULL);
}
