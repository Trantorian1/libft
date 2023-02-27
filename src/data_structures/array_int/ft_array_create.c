/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:58:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/27 13:58:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_create.h"

#include "ft_closest_power_ul.h"
#include "ft_calloc.h"
#include <stdlib.h>

t_s_array	*ft_array_create(size_t size)
{
	t_s_array	*array;
	size_t		size_new;

	array = malloc(sizeof(*array));
	if (!array)
		return (NULL);
	size_new = ft_closest_power_ul(size, 2);
	array->data = ft_calloc(size_new, sizeof(array->data));
	if (!array->data)
		return ((void)free(array), NULL);
	array->footprint = size_new;
	array->index = 0;
	return (array);
}
