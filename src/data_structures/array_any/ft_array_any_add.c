/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:05:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_add.h"

#include "ft_closest_power_ul.h"
#include "ft_memcpy.h"
#include "ft_malloc.h"
#include <stdlib.h>
#include <stdbool.h>

static void	ft_array_any_resize(t_s_array_any *array, size_t size)
{
	size_t		size_new;
	const void	**data_new;

	if (array->index + size >= array->footprint * 2)
		size_new = ft_closest_power_ul(array->index + size, 2);
	else
		size_new = array->footprint * 2;
	data_new = ft_malloc(size_new * sizeof(*data_new));
	ft_memcpy(data_new, array->data, array->footprint * sizeof(*data_new));
	ft_free(array->data);
	array->data = data_new;
	array->footprint = size_new;
}

static bool	ft_array_any_should_resize(t_s_array_any *array, size_t size)
{
	return (array->index + size >= array->footprint);
}

void	ft_array_any_add(t_s_array_any *array, const void *any)
{
	if (!array || !any)
		return ;
	if (ft_array_any_should_resize(array, 0))
		ft_array_any_resize(array, 0);
	array->data[array->index++] = any;
}

void	ft_array_any_add_at(t_s_array_any *array, const void *any, size_t index)
{
	if (!array || !any)
		return ;
	if (ft_array_any_should_resize(array, index))
		ft_array_any_resize(array, index);
	array->data[index] = any;
	array->index = index + 1;
}

void	ft_array_any_add_bulk(
	t_s_array_any *array,
	const void **data,
	size_t size)
{
	if (!array || !data)
		return ;
	if (ft_array_any_should_resize(array, size))
		ft_array_any_resize(array, size);
	ft_memcpy(array->data + array->index, data, size * sizeof(*data));
	array->index += size;
}
