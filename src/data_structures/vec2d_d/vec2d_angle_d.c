/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_angle_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:11:01 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/15 15:18:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_angle_d.h"

#include <float.h>
#include <math.h>

double	vec2d_angle_d(t_s_vec2d_d *vect)
{
	if (vect->x >= 0 && vect->x <= DBL_EPSILON)
	{
		if (vect->y >= 0)
			return (M_PI_2);
		else
			return (-M_PI_2);
	}
	return (atan2(vect->y, vect->x));
}
