/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:35 by arobu             #+#    #+#             */
/*   Updated: 2023/01/26 18:07:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_abs_double(double value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}