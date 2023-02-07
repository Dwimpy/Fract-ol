/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:44:01 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 20:42:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"

static void	no_arguments(void);
static char	*str_toupper(char **str);
static int	is_valid_args(int argc, char **argv);

void	arg_checker(int argc, char **argv)
{
	if (argc < 2)
		no_arguments();
	else if (argc >= 2)
	{
		if (is_valid_args(argc, argv) == -1)
		{
			ft_putstr_fd("\033[0;91mError:\033[0;39m ", 2);
			ft_putstr_fd("Invalid input", 2);
			exit(0);
		}
	}
}

static void	no_arguments(void)
{
	ft_putstr_fd("\033[0;91mError:\033[0;39m ", 2);
	ft_putstr_fd("No arguments given\n\
Please specify a fractal to render:\n", 2);
	ft_putstr_fd("usage: ./fractol [fractal] [options]\n", 2);
	ft_putstr_fd("Available fractals:\n", 2);
	ft_putstr_fd("\
1:\t[ \033[0;93mMandelbrot\033[0;39m ]\n\
2:\t[ \033[0;93mJulia\033[0;39m ] [ \033[0;93mPARAMS\033[0;39m ]\n\
3:\t[ \033[0;93mBurning Ship\033[0;39m ]", 2);
	exit(0);
}

static int	is_valid_args(int argc, char **argv)
{
	argv[1] = str_toupper(&argv[1]);
	if (ft_strncmp(argv[1], "MANDELBROT", 10) == 0)
		return (0);
	else if (ft_strncmp(argv[1], "JULIA", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[1], "BURNING SHIP", 12) == 0)
		return (0);
	else if (argc > 2 && ft_strncmp(argv[1], "BURNING", 7) == 0 && \
		ft_strncmp(str_toupper(&argv[2]), "SHIP", 4) == 0)
		return (0);
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
