/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:05:36 by arobu             #+#    #+#             */
/*   Updated: 2023/01/25 20:35:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define DEFAULT_RESIZE_OPTION 1
# define W_WIDTH 1024
# define W_HEIGHT 1024
# define W_TITLE "Fract-ol"
# define W_RESIZEABLE 1
# define BG_BLACK 0
# define BG_WHITE 255
typedef enum e_bg_color
{
	BLACK = 0,
	WHITE = 255
}			t_bg_color;

typedef struct s_window
{
	int			width;
	int			height;
	char		*title;
	int			is_resizeable;
	t_bg_color	bg_color;
}				t_window;

t_window	create_window(int width, int height, char *title, int isresizeable);
int			set_window_background(t_bg_color bg_color);
#endif