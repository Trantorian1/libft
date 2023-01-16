/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_front_bulk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:37:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/16 14:47:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_front_bulk.h"

#include <stdlib.h>
#include "ft_memcpy.h"

int	*ft_deque_poll_front_bulk(t_s_deque *deque, size_t n)
{
	int	*data;
	int	*bottom;

	if (n > deque->size_actual)
		return (NULL);
	data = malloc(n * sizeof(*data));
	if (!data)
		return (NULL);
	bottom = (deque->data + deque->bottom + deque->size_actual - n);
	ft_memcpy(data, bottom, n * sizeof(*data));
	return (data);
}
