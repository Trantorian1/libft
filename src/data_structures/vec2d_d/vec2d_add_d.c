/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_add_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 15:46:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_add_d.h"

t_s_vec2d_d	*vec2d_add_d(t_s_vec2d_d *dest, t_s_vec2d_d *source)
{
	dest->x += source->x;
	dest->y += source->y;
	return (dest);
}
