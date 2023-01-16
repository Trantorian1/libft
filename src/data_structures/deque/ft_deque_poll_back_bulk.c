/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_back_bulk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:39:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/16 14:45:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_back_bulk.h"

#include <stdlib.h>
#include "ft_memcpy.h"

int	*ft_deque_poll_back_bulk(t_s_deque *deque, size_t n)
{
	int	*data;

	if (n > deque->size_actual)
		return (NULL);
	data = malloc(n * sizeof(*data));
	if (!data)
		return (NULL);
	ft_memcpy(data, deque->data + deque->bottom, n * sizeof(*data));
	return (data);
}
