/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:38:33 by arobu             #+#    #+#             */
/*   Updated: 2023/01/23 20:06:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

double	mangnitude(t_complex *z)
{
	return (sqrt(z->real * z->real + z->imag * z->imag));
}

double	mag_squared(t_complex *z)
{
	return (z->real * z->real + z->imag * z->imag);
}

t_complex	conjugate(t_complex z)
{
	t_complex	result;

	result.real = z.real;
	result.imag = (-1) * z.imag;
	return (result);
}

void	square(t_complex *z)
{
	multiply(z, z->real, z->imag);
}

// t_complex	inverse(t_complex z)
// {
// 	t_complex	result;
// 	t_complex	z_cc;
// 	t_complex	denominator;

// 	z_cc = conjugate(z);
// 	denominator.real = (z.real * z_cc.real - z.imag * z_cc.imag);
// 	denominator.imag = (z.real * z_cc.imag + z.imag * z_cc.real);
// 	result = division(z_cc, denominator);
// 	return (result);
// }