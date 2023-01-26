/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:05 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 10:23:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_insert.h"

#include "ft_memcpy.h"
#include "ft_closest_power_ul.h"
#include "errors.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	ft_array_any_in_bounds(t_s_array_any *array, size_t index)
{
	return (index < array->index);
}

int	ft_array_any_insert(t_s_array_any *array, size_t index, void *any)
{
	if (!ft_array_any_in_bounds(array, index))
		return (SIZE_ERROR);
	array->data[index] = any;
	return (NO_ERROR);
}

int	ft_array_any_insert_bulk(t_s_array_any *array, size_t index, void **data, size_t size)
{
	if (!ft_array_any_in_bounds(array, index)
		|| !ft_array_any_in_bounds(array, index + size - 1))
		return (SIZE_ERROR);
	ft_memcpy(&array->data[index], data, size * sizeof(*data));
	return (NO_ERROR);
}
