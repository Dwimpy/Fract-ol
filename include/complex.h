/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/23 20:07:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
# include "../libft/include/ft_printf.h"
# include "stdio.h"

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

t_complex	*add(t_complex *z1, double real, double imag);
t_complex	subtract(t_complex z1, t_complex z2);
t_complex	s_multiply(double scalar, t_complex z);
t_complex	division(t_complex z1, t_complex z2);
void		multiply(t_complex *z1, double real, double imag);

void		square(t_complex *z);
t_complex	conjugate(t_complex z);
t_complex	inverse(t_complex z);
double		mangnitude(t_complex *z);
double		mag_squared(t_complex *z);

/*
######################################
#              Printing	             #
######################################
*/

void		print_complex(t_complex z);
void		print_complex_operation(t_complex z, char *operation);
void		print_complex_name(t_complex z, char *name);

#endif