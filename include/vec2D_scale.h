/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_scale.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:45:00 by                   #+#    #+#             */
/*   Updated: 2023/03/06 19:49:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2D_SCALE_H
# define VEC2D_SCALE_H

# include <stdint.h>
# include "s_vec2D.h"

t_s_vec2d	*vec2d_scale_int(t_s_vec2d vec, int32_t scalar);

#endif
