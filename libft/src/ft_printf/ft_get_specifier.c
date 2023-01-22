/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:19 by arobu             #+#    #+#             */
/*   Updated: 2022/11/21 20:16:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_get_specifier(t_fields *field, const char *format)
{
	size_t	count;

	count = 0;
	field -> specifier = format[count];
	count++;
	return (count);
}
