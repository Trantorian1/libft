/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:36:10 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 11:16:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDS_H
# define BOUNDS_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_bounds
{
	size_t	min;
	size_t	max;
}	t_s_bounds;

t_s_bounds	*ft_bounds_new(size_t min, size_t max);
void		*ft_bounds_destroy(t_s_bounds *bounds);
void		ft_bounds_resize(t_s_bounds *bounds, size_t min, size_t max);
bool		ft_is_in_bound(t_s_bounds *bounds, int n);

#endif
