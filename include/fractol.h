/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:20:40 by arobu             #+#    #+#             */
/*   Updated: 2023/02/11 15:47:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "complex.h"
# include "renderer.h"
# include "data.h"

void	fractol(t_arg_opts *args);
void	arg_checker(int argc, char **argv, t_arg_opts *args);
#endif
