/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:35:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/07 09:25:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2D_scale.h"

#include "vec2D_new.h"

t_s_vec2d	*vec2d_scale_int(t_s_vec2d *vec, int32_t scalar)
{
	return (vec2d_new(vec->x * scalar, vec->y * scalar));
}
