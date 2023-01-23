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

// #include "MLX42/include/MLX42/MLX42.h"
// #include "libft/include/ft_printf.h"
#include "../include/complex.h"
// int	main(int argc, char **argv)
// {
// 	test_repeated_complex_pow_v2();
// 	return (0);
// }

int	main(int argc, char **argv)
{
	// mlx_t		*mlx;
	// mlx_image_t	*image;

	// mlx = mlx_init(1024,1024, "Fract'ol", true);
	// image = mlx_new_image(mlx, 128, 128);
	// ft_memset(image->pixels, 255, image->width * image->height * sizeof(int));
	// mlx_image_to_window(mlx, image, 512 - 128/2, 512 - 128/2);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	t_complex	c;
	t_complex	z;
	c.real = -2;
	int iteration;
	size_t count;
	count = 0;
	double escape_value = 2.0;
	while (c.real < 1)
	{
		c.imag = 1;

		while (c.imag > -1)
		{
			iteration = 100;
			z.real = 0;
			z.imag = 0;
			while (iteration > 0 && mangnitude(&z) <= escape_value)
			{
				// printf("%.2f\n", norm(z));
				multiply(&z, z.real, z.imag);
				add(&z, c.real, c.imag);
				iteration--;
			}
			//printf("%.2f\t%.2f\n", z.real, z.imag);
			c.imag -= 0.01;
		}
		c.real += 0.01;
	}
	// t_complex	z1 = {4, 3};
	// t_complex	z2 = {3, 4};
	// t_complex	result;
	// print_complex_name(z1, "z1");
	// print_complex_name(z2, "z2");
	// result = add(z1,z2);
	// print_complex_operation(result, "Addition");
	// result = subtract(z1,z2);
	// print_complex_operation(result, "Subtraction");
	// double the_norm = norm(z1);
	// printf("Norm: [%.2f]\n", the_norm);
	// result = multiply(z1, z2);
	// print_complex_operation(result, "Multiplication");
	// result = division(z1, z2);
	// print_complex_operation(result, "Division");
	// result = inverse(z1);
	// print_complex_operation(result, "Inverse");
	return (0);
}