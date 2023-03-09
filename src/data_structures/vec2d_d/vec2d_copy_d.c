/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_copy_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:32:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 10:34:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_copy_d.h"

t_s_vec2d_d	*vec2d_copy_d(t_s_vec2d_d *dest, t_s_vec2d_d source)
{
	dest->x = source.x;
	dest->y = source.y;
	return (dest);
}
