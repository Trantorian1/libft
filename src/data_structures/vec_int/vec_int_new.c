/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_int_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:32:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 19:33:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int_new.h"

#include "ft_malloc.h"

t_s_vec_int	*vec_int_new(int32_t x, int32_t y)
{
	t_s_vec_int	*vec;

	vec = ft_malloc(sizeof(*vec));
	vec->x = x;
	vec->y = y;
	return (vec);
}
