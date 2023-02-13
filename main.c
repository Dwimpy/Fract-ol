/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:16:17 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 20:40:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_arg_opts	args;

	init_args(&args);
	arg_checker(argc, argv, &args);
	parse_arg_options(argv, &args);
	fractol(&args);
	return (EXIT_SUCCESS);
}
