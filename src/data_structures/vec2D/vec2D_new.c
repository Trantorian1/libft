/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:32:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 19:49:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2D_new.h"

#include "ft_malloc.h"

t_s_vec2d	*vec2d_new(int32_t x, int32_t y)
{
	t_s_vec2d	*vec;

	vec = ft_malloc(sizeof(*vec));
	vec->x = x;
	vec->y = y;
	return (vec);
}
