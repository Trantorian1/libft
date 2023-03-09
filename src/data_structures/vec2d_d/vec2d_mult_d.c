/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_mult_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:45:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 10:46:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_mult_d.h"

t_s_vec2d_d	*vec2d_mult_d(t_s_vec2d_d *source, double scalar)
{
	source->x *= scalar;
	source->y *= scalar;
	return (source);
}
