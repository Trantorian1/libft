/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:21:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:24:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_m_deque.h"

#include "ft_deque.h"
#include "ft_deque_push_front_bulk.h"
#include "ft_m_data.h"
#include "ft_malloc.h"

t_s_deque	*ft_mock_deque(int min, int max)
{
	t_s_deque	*deque_mock;
	int			*data_mock;

	deque_mock = ft_deque_new((size_t)(max - min));
	if (!deque_mock)
		return (NULL);
	data_mock = ft_mock_data(min, max);
	ft_deque_push_front_bulk(deque_mock, data_mock, (size_t)(max - min));
	ft_free(data_mock);
	return (deque_mock);
}
