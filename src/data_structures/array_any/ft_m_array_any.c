/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_array_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:06:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_m_array_any.h"

#include "ft_array_any_create.h"
#include "ft_array_any_add.h"
#include "ft_m_any.h"
#include "ft_malloc.h"

t_s_array_any	*ft_mock_array_any(int min, int max)
{
	t_s_array_any	*array;
	const void		**data;

	array = ft_array_any_create((size_t)(max - min));
	data = (const void **)ft_mock_any_create((size_t)(max - min));
	if (!data)
		return (ft_free(array), NULL);
	ft_array_any_add_bulk(array, data, (size_t)(max - min));
	ft_free(data);
	return (array);
}
