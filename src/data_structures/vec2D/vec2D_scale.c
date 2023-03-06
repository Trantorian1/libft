/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:35:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 20:03:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2D_scale.h"

#include "vec2D_new.h"

t_s_vec2d	*vec2d_scale_int(t_s_vec2d *vec, int32_t scalar)
{
	vec->x *= scalar;
	vec->y *= scalar;
	return (vec);
}
