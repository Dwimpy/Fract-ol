/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:37 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 14:40:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
# include "ft_printf.h"
# include "stdio.h"
# define LOG_2_DIV 0.30102999566398119521373889472449

/*
######################################
#      Complex Number Interface      #
######################################
#  A simple complex number interface #
# that offers basic functionalty for #
# mathematical operations for x ∈ ℂ  #
######################################
*/

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

/*
######################################
#          Basic Operations          #
######################################
*/

void		set_complex(t_complex *z, double real, double imag);
void		add(t_complex *z1, double real, double imag);
void		subtract(t_complex *z1, double real, double imag);
void		s_multiply(t_complex *z, double scalar);
void		division(t_complex *z1, double real, double imag);
void		multiply(t_complex *z1, double real, double imag);
void		square(t_complex *z);

double		mangnitude(double real, double imag);
double		mag_squared(double real, double imag);

t_complex	inverse(double real, double imag);
void		conjugate(t_complex *z, double real, double imag);

void		mandelbrot_equation(t_complex *z, t_complex *c);
void		mandelbrot_der_equation(t_complex *dz, \
										t_complex *z, t_complex dc);
void		burning_ship_der_eq(t_complex *dz, t_complex *z, t_complex dc);
void		burning_ship_eq(t_complex *z, t_complex *c);

double		color(double z_mag_sq);

/*
######################################
#              Printing	             #
######################################
*/

void		print_complex(t_complex z);
void		print_complex_operation(t_complex z, char *operation);
void		print_complex_name(t_complex z, char *name);

#endif
