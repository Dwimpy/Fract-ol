/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:01:32 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 14:44:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

void	set_complex(t_complex *z, double real, double imag)
{
	z->real = real;
	z->imag = imag;
}
