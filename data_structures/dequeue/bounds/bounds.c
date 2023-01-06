/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:47:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 11:17:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounds.h"

t_s_bounds	*ft_bounds_new(size_t min, size_t max)
{
	t_s_bounds	*bounds;

	bounds = malloc(sizeof(*bounds));
	if (!bounds)
		return (NULL);
	bounds->min = min;
	bounds->max = max;
	return (bounds);
}

void	*ft_bounds_destroy(t_s_bounds *bounds)
{
	free(bounds);
	return (NULL);
}

void	ft_bounds_resize(t_s_bounds *bounds, size_t min, size_t max)
{
	bounds->min = min;
	bounds->max = max;
}

bool	ft_is_in_bound(t_s_bounds *bounds, int n)
{
	return (n >= bounds->min && n <= bounds->max);
}
