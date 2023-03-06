/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:35:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 19:36:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_scale_int.h"

#include "vec_int_new.h"

t_s_vec_int	*vec_scale_int(t_s_vec_int vec, int32_t scalar)
{
	return (vec_int_new(vec.x * scalar, vec.y * scalar));
}
