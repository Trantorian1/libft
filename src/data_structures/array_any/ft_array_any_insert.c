/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:05 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/26 16:15:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_insert.h"

#include "ft_memcpy.h"
#include "ft_error_handle.h"
#include <stdbool.h>

static bool	ft_array_any_in_bounds(t_s_array_any *array, size_t index)
{
	return (index < array->index);
}

void	ft_array_any_insert(t_s_array_any *array, size_t index, void *any)
{
	if (!ft_array_any_in_bounds(array, index))
		return ;
	array->data[index] = any;
}

void	ft_array_any_insert_bulk(
	t_s_array_any *array,
	size_t index,
	void **data,
	size_t size)
{
	if (!ft_array_any_in_bounds(array, index)
		|| !ft_array_any_in_bounds(array, index + size - 1))
		return ;
	ft_memcpy(&array->data[index], data, size * sizeof(*data));
}
