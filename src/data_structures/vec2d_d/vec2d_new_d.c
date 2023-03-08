/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_new_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:14:06 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:16:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d_new_d.h"

#include "ft_malloc.h"

t_s_vec2d_d	*vec2d_new_d(double x, double y)
{
	t_s_vec2d_d	*vec2d_d;

	vec2d_d = ft_malloc(sizeof(*vec2d_d));
	vec2d_d->x = x;
	vec2d_d->y = y;
	return (vec2d_d);
}
