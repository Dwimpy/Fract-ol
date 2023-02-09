/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:16:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/22 21:02:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{

	// mlx_t		*mlx;
	// mlx_image_t	*image;

	// mlx = mlx_init(1024,1024, "Fract'ol", true);
	// image = mlx_new_image(mlx, 1024, 1024);
	// ft_memset(image->pixels, 0, image->width * image->height * sizeof(int));
	// mlx_image_to_window(mlx, image, 0, 0);
	// mlx_put_pixel(image, 25, 25, 0x00FFFFFF);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// if (argc == 1)
	// 	return (0);
	arg_checker(argc, argv);
	fractol();
	return (EXIT_SUCCESS);
}
