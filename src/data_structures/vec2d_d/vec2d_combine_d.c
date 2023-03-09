/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_combine_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 11:21:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_combine_d.h"

t_s_vec2d_d	*vec2d_combine_d(t_s_vec2d_d *dest, t_s_vec2d_d source)
{
	dest->x += source.x;
	dest->y += source.y;
	return (dest);
}
