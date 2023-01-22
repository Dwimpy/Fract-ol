/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:18:12 by arobu             #+#    #+#             */
/*   Updated: 2023/01/22 21:02:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

t_complex	add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imag = z1.imag + z2.imag;
	return (result);
}

t_complex	subtract(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real - z2.real;
	result.imag = z1.imag - z2.imag;
	return (result);
}

t_complex	s_multiply(double scalar, t_complex z)
{
	t_complex	result;

	result.real *= scalar;
	result.imag *= scalar;
	return (result);
}

t_complex	multiply(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real * z2.real - z1.imag * z2.imag;
	result.imag = z1.real * z2.imag + z2.real * z1.imag;
	return (result);
}

t_complex	division(t_complex z1, t_complex z2)
{
	t_complex	result;
	t_complex	z2_cc;
	t_complex	numerator;
	t_complex	denominator;

	z2_cc = conjugate(z2);
	numerator = multiply(z1, z2_cc);
	denominator = multiply(z2, z2_cc);
	result.real = numerator.real / denominator.real;
	result.imag = numerator.imag / denominator.real;
	return (result);
}
