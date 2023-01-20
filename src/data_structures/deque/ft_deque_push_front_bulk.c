/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push_front_bulk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:38:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/20 14:18:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_push_front_bulk.h"

#include "errors.h"
#include "ft_deque_ensure_space_top_bulk.h"
#include "ft_memcpy.h"

int	ft_deque_push_front_bulk(t_s_deque *deque, int *data, size_t n)
{
	int	error_code;

	error_code = ft_deque_ensure_space_top_bulk(deque, n);
	if (error_code)
		return (error_code);
	ft_memcpy(deque->data + deque->top + 1, data, n * sizeof(*data));
	deque->top += n;
	deque->size_actual += n;
	return (NO_ERROR);
}
