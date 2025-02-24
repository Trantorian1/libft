/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:09:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_m_array.h"

#include "ft_array_create.h"
#include "ft_array_add.h"
#include "ft_m_data.h"
#include "ft_malloc.h"

t_s_array	*ft_mock_array(int min, int max)
{
	t_s_array	*array;
	const int	*data;

	array = ft_array_create((size_t)(max - min));
	data = ft_mock_data(min, max);
	if (!data)
		return ((void)ft_free((void *)array), NULL);
	ft_array_add_bulk(array, data, (size_t)(max - min));
	return (array);
}
