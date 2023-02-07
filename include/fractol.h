/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:20:40 by arobu             #+#    #+#             */
/*   Updated: 2023/02/07 20:10:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "complex.h"
# include "renderer.h"
# include "data.h"

void	fractol(void);
void	arg_checker(int argc, char **argv);
#endif
