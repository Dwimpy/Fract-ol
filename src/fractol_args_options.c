/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_args_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:45:16 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 01:37:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/color.h"
#include "../include/data.h"

static int	get_channel_color(char *str, char *channel, size_t len);

void	change_options_color(t_arg_opts *args, \
							uint32_t r, uint32_t g, uint32_t b)
{
	args->color.r = r;
	args->color.g = g;
	args->color.b = b;
}

char	*get_arg_string(char **argv)
{
	uint32_t	i;
	char		*arg_str;
	char		*tmp;

	i = 2;
	arg_str = ft_strdup(argv[1]);
	while (argv[i] != NULL)
	{
		tmp = arg_str;
		arg_str = ft_strjoin_three(arg_str, " ", argv[i]);
		if (tmp != NULL)
			free(tmp);
		i++;
	}
	return (arg_str);
}

void	get_color_args(char **argv, t_arg_opts *args)
{
	char			*arg_str;
	char			*color_args;

	arg_str = get_arg_string(argv);
	color_args = ft_strnstr(arg_str, "-c", ft_strlen(arg_str));
	if (color_args != NULL)
	{
		if (*(color_args - 1) != ' ' || *(color_args + 2) != ' ')
		{
			fractol_usage("Invalid option\n");
			exit(EXIT_FAILURE);
		}
		args->color.r = get_channel_color(color_args, "red=", 4);
		args->color.g = get_channel_color(color_args, "green=", 6);
		args->color.b = get_channel_color(color_args, "blue=", 5);
	}
	free(arg_str);
}

static int	get_channel_color(char *str, char *channel, size_t len)
{
	char			*chan_color;
	int				color;

	chan_color = ft_strnstr(str, channel, ft_strlen(str));
	if (chan_color != NULL)
	{
		chan_color = ft_substr(chan_color, len, \
			ft_strchr(chan_color, ' ') - (chan_color + len));
		if (!ft_isdigit(chan_color[0]))
		{
			fractol_usage("Invalid color value.\n\
Must be a number between 0 and 255\n");
			exit(EXIT_FAILURE);
		}
		if (ft_atoi(chan_color) > 255 || ft_atoi(chan_color) < 0)
		{
			fractol_usage("Invalid color value.\n\
Must be a number between 0 and 255\n");
			exit(EXIT_FAILURE);
		}
		color = ft_atoi(chan_color);
		free(chan_color);
	}
	else
		color = 255;
	return (color);
}

void	parse_arg_options(t_arg_opts *args)
{
	if (args->mandelbrot == true)
	{

	}
}
