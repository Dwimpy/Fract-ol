/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:18:12 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 19:02:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

void	add(t_complex *z1, double real, double imag)
{
	z1->real += real;
	z1->imag += imag;
}

void	subtract(t_complex *z1, double real, double imag)
{
	z1->real -= real;
	z1->imag -= imag;
}

void	s_multiply(t_complex *z, double scalar)
{
	z->real *= scalar;
	z->imag *= scalar;
}

void	multiply(t_complex *z1, double real, double imag)
{
	double	real_z;

	real_z = z1->real;
	z1->real = z1->real * real - z1->imag * imag;
	z1->imag = real_z * imag + real * z1->imag;
}

void	division(t_complex *z1, double real, double imag)
{
	double		norm_squared;
	t_complex	z_cc;

	z_cc = conjugate(real, imag);
	norm_squared = mag_squared(z_cc.real, z_cc.imag);
	multiply(z1, z_cc.real, z_cc.imag);
	print_complex_operation(z_cc, "Conjugate");
	print_complex_operation(*z1, "Z1");
	z1->real /= norm_squared;
	z1->imag /= norm_squared;
}
