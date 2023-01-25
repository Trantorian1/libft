/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_mock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 18:37:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_mock.h"

#include "ft_array_create.h"
#include "ft_array_add.h"
#include "ft_data_mock.h"
#include <stdlib.h>

t_s_array	*ft_array_mock(int min, int max)
{
	t_s_array	*array;
	int			*data;

	array = ft_array_create((size_t)(max - min));
	data = ft_data_mock(min, max);
	if (!data)
		return (free(array), NULL);
	ft_array_add_bulk(array, data, (size_t)(max - min));
	return (array);
}
