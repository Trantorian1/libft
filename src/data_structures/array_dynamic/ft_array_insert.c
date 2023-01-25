/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:05 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 19:02:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_insert.h"

#include "ft_memcpy.h"
#include "ft_closest_power_ul.h"
#include "errors.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	ft_array_in_bounds(t_s_array *array, size_t index)
{
	return (index < array->index);
}

int	ft_array_insert(t_s_array *array, size_t index, int n)
{
	if (!ft_array_in_bounds(array, index))
		return (SIZE_ERROR);
	array->data[index] = n;
	return (NO_ERROR);
}

int	ft_array_insert_bulk(t_s_array *array, size_t index, int *data, size_t size)
{
	if (!ft_array_in_bounds(array, index)
		|| !ft_array_in_bounds(array, index + size - 1))
		return (SIZE_ERROR);
	ft_memcpy(&array->data[index], data, size * sizeof(*data));
	return (NO_ERROR);
}
