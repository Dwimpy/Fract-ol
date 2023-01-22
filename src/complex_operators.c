/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:38:33 by arobu             #+#    #+#             */
/*   Updated: 2023/01/22 20:24:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

double	norm(t_complex z)
{
	double	result;

	result = sqrt(pow(z.real, 2) + pow(z.imag, 2));
	return (result);
}

t_complex	conjugate(t_complex z)
{
	t_complex	result;

	result.real = z.real;
	result.imag = (-1) * z.imag;
	return (result);
}

t_complex	square(t_complex z)
{
	t_complex	result;

	result.real = pow(z.real, 2) - pow(z.imag, 2);
	result.imag = 2 * z.real * z.imag;
	return (result);
}

t_complex	inverse(t_complex z)
{
	t_complex	result;
	t_complex	z_cc;
	t_complex	denominator;

	z_cc = conjugate(z);
	denominator = multiply(z, z_cc);
	result = division(z_cc, denominator);
	return (result);
}