/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:30:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/07 09:24:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2D_add.h"

#include "vec2D_new.h"

t_s_vec2d	*vec2d_add(t_s_vec2d *a, t_s_vec2d *b)
{
	return (vec2d_new(a->x + b->x, a->y + b->y));
}
