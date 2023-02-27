/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/27 13:58:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_add.h"

#include "ft_closest_power_ul.h"
#include "ft_memcpy.h"
#include <stdlib.h>
#include <stdbool.h>

static void	ft_array_resize(t_s_array *array, size_t size)
{
	size_t	size_new;
	int		*data_new;

	if (array->index + size >= array->footprint * 2)
		size_new = ft_closest_power_ul(array->index + size, 2);
	else
		size_new = array->footprint * 2;
	data_new = malloc(size_new * sizeof(*data_new));
	if (!data_new)
		return ;
	ft_memcpy(data_new, array->data, array->footprint * sizeof(*data_new));
	free(array->data);
	array->data = data_new;
	array->footprint = size_new;
}

static bool	ft_array_should_resize(t_s_array *array, size_t size)
{
	return (array->index + size >= array->footprint);
}

void	ft_array_add(t_s_array *array, int n)
{
	if (ft_array_should_resize(array, 1))
		ft_array_resize(array, 1);
	array->data[array->index++] = n;
}

void	ft_array_add_bulk(t_s_array *array, const int *data, size_t size)
{
	if (ft_array_should_resize(array, size))
		ft_array_resize(array, size);
	ft_memcpy(array->data + array->index, data, size * sizeof(*data));
	array->index += size;
}
