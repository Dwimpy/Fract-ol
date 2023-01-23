/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:18:12 by arobu             #+#    #+#             */
/*   Updated: 2023/01/23 20:07:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

t_complex	*add(t_complex *z1, double real, double imag)
{
	z1->real += real;
	z1->imag += imag;
	return (z1);
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

void	multiply(t_complex *z1, double real, double imag)
{
	double real_z;

	real_z = z1->real;
	z1->real = z1->real * real - z1->imag * imag;
	z1->imag = real_z * imag + real * z1->imag;
}

// t_complex	division(t_complex z1, t_complex z2)
// {
// 	t_complex	result;
// 	t_complex	z2_cc;
// 	t_complex	numerator;
// 	t_complex	denominator;

// 	z2_cc = conjugate(z2);
// 	numerator = multiply(&z1, &z2_cc);
// 	denominator = multiply(&z2, &z2_cc);
// 	result.real = numerator.real / denominator.real;
// 	result.imag = numerator.imag / denominator.real;
// 	return (result);
// }
