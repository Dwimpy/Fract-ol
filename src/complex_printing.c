/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:21:32 by arobu             #+#    #+#             */
/*   Updated: 2023/01/22 21:01:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

void	print_complex(t_complex z)
{
	printf("z = [%.2f] + [%.2f\u22c5i]\n", z.real, z.imag);
}

void	print_complex_name(t_complex z, char *name)
{
	printf("%s = [%.2f] + [%.2f\u22c5i]\n", name, z.real, z.imag);
}

void	print_complex_operation(t_complex z, char *operation)
{
	printf("%s: Result = [%.2f] + [%.2f\u22c5i]\n", operation, z.real, z.imag);
}