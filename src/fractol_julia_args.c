/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:19:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/13 17:31:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"

static void	check_params_valid(char c, int *has_digits);

void	check_julia_args(char *str)
{
	size_t	len;
	size_t	i;
	int		has_digits;

	has_digits = 0;
	i = 0;
	if (str != NULL && str[i] != '\0')
	{
		len = ft_strlen(str);
		while (len-- > 0)
		{
			check_params_valid(str[i], &has_digits);
			i++;
		}
	}
	if (has_digits == 0)
	{
		fractol_usage("Invalid julia argument.\n");
		exit(EXIT_FAILURE);
	}
}

static void	check_params_valid(char c, int *has_digits)
{
	if (ft_isdigit(c))
		*has_digits = 1;
	if (!ft_isdigit(c) && c != '.' && c != '-')
	{
		fractol_usage("Invalid julia argument.\n");
		exit(EXIT_FAILURE);
	}
}
