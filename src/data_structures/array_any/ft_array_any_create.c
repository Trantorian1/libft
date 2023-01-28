/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:59:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 14:45:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_create.h"

#include "e_error.h"
#include "ft_closest_power_ul.h"
#include "ft_calloc.h"
#include "ft_error_handle.h"
#include <stdlib.h>

t_s_array_any	*ft_array_any_create(size_t size)
{
	t_s_array_any	*array;
	size_t			size_new;

	array = malloc(sizeof(*array));
	if (!array)
		return (ft_error_throw(ERROR_MALLOC), NULL);
	size_new = ft_closest_power_ul(size, 2);
	array->data = ft_calloc(size_new, sizeof(array->data));
	if (!array->data)
		return (free(array), ft_error_throw(ERROR_MALLOC), NULL);
	array->footprint = size_new;
	array->index = 0;
	return (array);
}
