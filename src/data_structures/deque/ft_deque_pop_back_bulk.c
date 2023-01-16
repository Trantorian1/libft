/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_back_bulk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:21:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/16 14:42:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_pop_back_bulk.h"

#include "ft_deque_poll_back_bulk.h"

int	*ft_deque_pop_back_bulk(t_s_deque *deque, size_t n)
{
	int	*data;

	data = ft_deque_poll_back_bulk(deque, n);
	if (!data)
		return (NULL);
	deque->bottom += n;
	deque->size_actual -= n;
	return (data);
}
