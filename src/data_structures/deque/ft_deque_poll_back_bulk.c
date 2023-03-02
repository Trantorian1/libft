/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_back_bulk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:39:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:10:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_back_bulk.h"

#include "ft_memcpy.h"
#include "ft_malloc.h"

int	*ft_deque_poll_back_bulk(t_s_deque *deque, size_t n)
{
	int	*data;

	if (!deque)
		return (NULL);
	if (n > deque->size_actual)
		return (NULL);
	data = ft_malloc(n * sizeof(*data));
	ft_memcpy(data, deque->data + deque->bottom, n * sizeof(*data));
	return (data);
}
