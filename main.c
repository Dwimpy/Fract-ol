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

#include "../include/complex.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "libft/include/ft_printf.h"

int	main(int argc, char **argv)
{


// 	mlx_t		*mlx;
// 	mlx_image_t	*image;

// 	mlx = mlx_init(1024,1024, "Fract'ol", true);
// 	image = mlx_new_image(mlx, 128, 128);
// 	ft_memset(image->pixels, 255, image->width * image->height * sizeof(int));
// 	mlx_image_to_window(mlx, image, 512 - 128/2, 512 - 128/2);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);

	t_complex	a;
	t_complex	b;

	set_complex(&a, 4, 3);
	set_complex(&b, 3, 4);
	add(&a, b.real, b.imag);
	print_complex_operation(a, "Addition");
	set_complex(&a, 4, 3);
	subtract(&a, b.real, b.imag);
	print_complex_operation(a, "Subtraction");
	set_complex(&a, 4, 3);
	multiply(&a, b.real, b.imag);
	print_complex_operation(a, "Multiplication");
	set_complex(&a, 4, 3);
	division(&a, b.real, b.imag);
	print_complex_operation(a, "Division");
	set_complex(&a, 3, 4);
	a = inverse(a.real, a.imag);
	multiply(&b, a.real, a.imag);
	print_complex_operation(b, "Inverse * Normal");
	return (0);
}