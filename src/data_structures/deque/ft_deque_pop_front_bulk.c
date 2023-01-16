/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_front_bulk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:31:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/16 14:48:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_pop_front_bulk.h"

#include "ft_deque_poll_front_bulk.h"

int	*ft_deque_pop_front_bulk(t_s_deque *deque, size_t n)
{
	int	*data;

	data = ft_deque_poll_front_bulk(deque, n);
	if (!data)
		return (NULL);
	deque->top -= n;
	deque->size_actual -= n;
	return (data);
}
