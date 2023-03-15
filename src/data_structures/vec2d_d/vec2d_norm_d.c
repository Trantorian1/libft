/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_norm_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:55:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/15 12:59:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_norm_d.h"

#include <math.h>

double	vec2d_norm_d(t_s_vec2d_d *vect)
{
	return (sqrt(vect->x * vect->x + vect->y * vect->y));
}
