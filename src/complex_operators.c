/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:38:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 19:01:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

double	mangnitude(double real, double imag)
{
	return (sqrt(real * real + imag * imag));
}

double	mag_squared(double real, double imag)
{
	return (real * real + imag * imag);
}

t_complex	conjugate(double real, double imag)
{
	t_complex	result;

	result.real = real;
	result.imag = (-1) * imag;
	return (result);
}

void	square(t_complex *z)
{
	multiply(z, z->real, z->imag);
}

t_complex	inverse(double real, double imag)
{
	t_complex	result;
	t_complex	z_cc;
	double		norm_squared;

	z_cc = conjugate(real, imag);
	norm_squared = mag_squared(real, imag);
	result.real = z_cc.real / norm_squared;
	result.imag = z_cc.imag / norm_squared;
	return (result);
}
