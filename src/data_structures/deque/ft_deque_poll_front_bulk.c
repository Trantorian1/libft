/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_front_bulk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:37:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:11:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_front_bulk.h"

#include "ft_memcpy.h"
#include "ft_malloc.h"

int	*ft_deque_poll_front_bulk(t_s_deque *deque, size_t n)
{
	int	*data;
	int	*bottom;

	if (!deque)
		return (NULL);
	if (n > deque->size_actual)
		return (NULL);
	data = ft_malloc(n * sizeof(*data));
	bottom = (deque->data + deque->bottom + deque->size_actual - n);
	ft_memcpy(data, bottom, n * sizeof(*data));
	return (data);
}
