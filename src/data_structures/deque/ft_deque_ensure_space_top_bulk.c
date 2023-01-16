/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_ensure_space_top_bulk.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:40:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/16 10:34:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_ensure_space_top_bulk.h"

#include <stdbool.h>
#include <stdlib.h>
#include "errors.h"
#include "ft_closest_power.h"
#include "ft_memcpy.h"

static int	ft_deque_grow_top_bulk(t_s_deque *deque, size_t n)
{
	size_t	size_new;
	size_t	size_delta;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = (size_t) ft_closest_power((int)(deque->size_data + n), 2);
	size_delta = (size_new - deque->size_actual - n) / 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + size_delta;
	ft_memcpy(
		bottom_new, bottom_old,
		deque->size_actual * sizeof(*new_array));
	free(deque->data);
	deque->bottom = size_delta;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
	return (NO_ERROR);
}

static bool	ft_deque_should_make_space_top(t_s_deque *deque, size_t n)
{
	return (deque->top + n > deque->size_data - 1);
}

int	ft_deque_ensure_space_top_bulk(t_s_deque *deque, size_t n)
{
	if (!ft_deque_should_make_space_top(deque, n))
		return (NO_ERROR);
	return (ft_deque_grow_top_bulk(deque, n));
}
