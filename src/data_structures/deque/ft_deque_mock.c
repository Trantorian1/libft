/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_mock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:21:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/24 11:36:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_mock.h"

#include "ft_deque.h"
#include "ft_deque_push_front_bulk.h"
#include "ft_data_mock.h"
#include <stdlib.h>

t_s_deque	*ft_deque_mock(int min, int max)
{
	t_s_deque	*deque_mock;
	int			*data_mock;

	deque_mock = ft_deque_new((size_t)(max - min));
	if (!deque_mock)
		return (NULL);
	data_mock = ft_data_mock(min, max);
	if (!data_mock)
		return (ft_deque_destroy(deque_mock));
	if (ft_deque_push_front_bulk(deque_mock, data_mock, (size_t)(max - min)))
		return (ft_deque_destroy(deque_mock));
	return (deque_mock);
}
