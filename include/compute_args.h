/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_args.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:17:31 by arobu             #+#    #+#             */
/*   Updated: 2023/02/12 16:20:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_ARGS_H
# define COMPUTE_ARGS_H
# include "complex.h"

typedef struct s_compute_args
{
	int			check;
	double		mag_sq;
	t_complex	dz;
	t_complex	dc;
	t_complex	saved_z;
}				t_compute_args;

#endif
