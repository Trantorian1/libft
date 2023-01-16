/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_add_back_bulk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:16:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/16 11:12:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_add_back_bulk.h"

#include "errors.h"
#include "ft_deque_ensure_space_back_bulk.h"
#include "ft_memcpy.h"

int	ft_deque_add_back_bulk(t_s_deque *deque, int *data, size_t n)
{
	int	error_code;

	error_code = ft_deque_ensure_space_back_bulk(deque, n);
	if (error_code)
		return (error_code);
	ft_memcpy(deque->data + deque->bottom - n, data, n * sizeof(*data));
	deque->bottom -= n;
	deque->size_actual += n;
	return (NO_ERROR);
}
