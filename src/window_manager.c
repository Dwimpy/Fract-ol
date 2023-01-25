/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:25:46 by arobu             #+#    #+#             */
/*   Updated: 2023/01/25 20:35:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

t_window	create_window(int width, int height, \
							char *title, int resizeable)
{
	t_window	window;

	window.width = width;
	window.height = height;
	window.title = title;
	window.is_resizeable = resizeable;
	return (window);
}

int	set_window_background(t_bg_color bg_color)
{
	if (bg_color == WHITE)
		return (BG_WHITE);
	else
		return (BG_BLACK);
}