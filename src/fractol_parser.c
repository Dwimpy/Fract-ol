/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:44:01 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 01:06:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include "../include/data.h"

static char	*str_toupper(char **str);
static int	is_valid_args(int argc, char **argv, t_arg_opts *args);

void	arg_checker(int argc, char **argv, t_arg_opts *args)
{
	if (argc < 2)
		fractol_usage("No arguments given\n\
Please specify a fractal to render:\n");
	if (is_valid_args(argc, argv, args) == -1)
	{
		fractol_usage("Invalid Fractal\n");
		exit(EXIT_FAILURE);
	}
}

void	fractol_usage(char *err_msg)
{
	ft_putstr_fd("\033[0;91mError:\033[0;39m ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("usage: ./fractol [fractal] [options]\n", 2);
	ft_putstr_fd("\033[0;94mAvailable Fractals:\033[0;39m\n", 2);
	ft_putstr_fd("\
1: [ \033[0;93mMandelbrot\033[0;39m ]\n\
2: [ \033[0;93mJulia\033[0;39m ] [ \033[0;93mPARAMS\033[0;39m ]\n\
3: [ \033[0;93mBurning Ship\033[0;39m ]\n", 2);
	ft_putstr_fd("\033[0;94mAdditional Options:\033[0;39m \n", 2);
	ft_putstr_fd("[ \033[0;93m-na\033[0;39m ] - Disable Animations\n", 2);
	ft_putstr_fd("[ \033[0;93m-c\033[0;39m  ] [ \033[0;93mr g b\033[0;39m ] \
- Choose Color Palette\n", 2);
	ft_putstr_fd("\033[0;94mExample:\033[0;39m  ./fractol Julia \
-c red=255 green=255 blue=255\n", 2);
	ft_putstr_fd("\033[0;91mCaution: \033[0;39m\n", 2);
	ft_putstr_fd("3: \033[0;94mNot specifying the \
channel will have no effect\033[0;39m \n", 2);
	exit(0);
}

static int	is_valid_args(int argc, char **argv, t_arg_opts *args)
{
	argv[1] = str_toupper(&argv[1]);
	if (ft_strncmp(argv[1], "MANDELBROT", 10) == 0)
	{
		args->mandelbrot = true;
		return (0);
	}
	else if (ft_strncmp(argv[1], "JULIA", 5) == 0)
	{
		args->julia = true;
		return (0);
	}
	else if (ft_strncmp(argv[1], "BURNING SHIP", 12) == 0)
	{
		args->burning_ship = true;
		return (0);
	}
	else if (argc > 2 && ft_strncmp(argv[1], "BURNING", 7) == 0 && \
		ft_strncmp(str_toupper(&argv[2]), "SHIP", 4) == 0)
	{
		args->burning_ship = true;
		return (0);
	}
	return (-1);
}

static char	*str_toupper(char **str)
{
	char	*begin;

	begin = *str;
	while (begin && *begin != '\0')
	{
		if (!ft_isalpha(*begin))
		{
			ft_putstr_fd("\033[0;91mError:\033[0;39m ", 2);
			ft_putstr_fd("Invalid input", 2);
			exit (EXIT_FAILURE);
		}
		if (*begin >= 'a' && *begin <= 'z')
			*begin -= 32;
		begin++;
	}
	return (*str);
}
