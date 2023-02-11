/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:52:16 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 18:35:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

void	create_fractal_stack(t_fractals **fractals)
{
	(*fractals) = (t_fractals *)malloc(sizeof(t_fractals));
	(*fractals)->front = NULL;
	(*fractals)->rear = NULL;
	(*fractals)->size = 0;
}

int	is_stack_empty(t_fractals *fractals)
{
	return (fractals->size == 0);
}

void	add_new_fractal(t_fractals **fractals)
{
	t_fractal_node	*new_fractal;

	new_fractal = create_empty_fractal();
	if (is_stack_empty(*fractals))
	{
		(*fractals)->front = new_fractal;
		(*fractals)->rear = new_fractal;
		(*fractals)->front->prev = (*fractals)->rear;
		(*fractals)->front->next = (*fractals)->rear;
		(*fractals)->rear->next = (*fractals)->front;
		(*fractals)->rear->prev = (*fractals)->front;
	}
	else
	{
		new_fractal->prev = (*fractals)->rear;
		new_fractal->next = (*fractals)->front;
		(*fractals)->rear -> next = new_fractal;
		(*fractals)->rear = (*fractals)->rear->next;
		(*fractals)->front->prev = (*fractals)->rear;
		(*fractals)->front = (*fractals)->front->next;
	}
	(*fractals)->size++;
}

void	destroy_stack(t_fractals **fractals, mlx_t *mlx)
{
	t_fractal_node	*current;
	t_fractal_node	*next;

	if (is_stack_empty(*fractals))
		return ;
	current = (*fractals)->front;
	next = current->next;
	while (current != (*fractals)->rear)
	{
		current = destroy_node(mlx, &current);
		current = next;
		next = current->next;
	}
	current = destroy_node(mlx, &current);
	free(*fractals);
	*fractals = NULL;
}
