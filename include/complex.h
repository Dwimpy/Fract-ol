/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/22 20:58:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
# include "../libft/include/ft_printf.h"
# include "stdio.h"

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

t_complex	add(t_complex z1, t_complex z2);
t_complex	subtract(t_complex z1, t_complex z2);
t_complex	s_multiply(double scalar, t_complex z);
t_complex	multiply(t_complex z1, t_complex z2);
t_complex	division(t_complex z1, t_complex z2);
t_complex	square(t_complex z);
t_complex	conjugate(t_complex z);
t_complex	inverse(t_complex z);
double		norm(t_complex z);

/*
######################################
#              Printing	             #
######################################
*/

void	print_complex(t_complex z);
void	print_complex_operation(t_complex z, char *operation);
void	print_complex_name(t_complex z, char *name);

#endif