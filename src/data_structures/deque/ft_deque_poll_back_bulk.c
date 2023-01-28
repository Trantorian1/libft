/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_back_bulk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:39:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 18:45:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_back_bulk.h"

#include "ft_memcpy.h"
#include "ft_error_handle.h"
#include <stdlib.h>

int	*ft_deque_poll_back_bulk(t_s_deque *deque, size_t n)
{
	int	*data;

	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM), NULL);
	if (n > deque->size_actual)
		return (ft_error_throw(ERROR_SIZE), NULL);
	data = malloc(n * sizeof(*data));
	if (!data)
		return (ft_error_throw(ERROR_MALLOC), NULL);
	ft_memcpy(data, deque->data + deque->bottom, n * sizeof(*data));
	return (data);
}
