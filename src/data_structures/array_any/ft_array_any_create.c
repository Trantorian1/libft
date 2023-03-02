/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:59:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:07:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_create.h"

#include "e_error.h"
#include "ft_closest_power_ul.h"
#include "ft_malloc.h"
#include "ft_calloc.h"

t_s_array_any	*ft_array_any_create(size_t size)
{
	t_s_array_any	*array;
	size_t			size_new;

	array = ft_malloc(sizeof(*array));
	size_new = ft_closest_power_ul(size, 2);
	array->data = ft_calloc(size_new, sizeof(array->data));
	array->footprint = size_new;
	array->index = 0;
	return (array);
}
