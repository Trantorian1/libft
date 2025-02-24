/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push_back_bulk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:16:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:16:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_push_back_bulk.h"

#include "e_error.h"
#include "ft_memcpy.h"
#include "ft_closest_power_ul.h"
#include "ft_malloc.h"
#include <stdbool.h>

static void	ft_deque_grow_bottom_bulk(t_s_deque *deque, size_t n)
{
	size_t	size_new;
	size_t	size_delta;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = ft_closest_power_ul(deque->size_data + n, 2);
	size_delta = (size_new - deque->size_data - n) / 2;
	new_array = ft_malloc(size_new * sizeof(*new_array));
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + size_delta + n;
	ft_memcpy(
		bottom_new, bottom_old,
		deque->size_actual * sizeof(*new_array));
	ft_free(deque->data);
	deque->bottom = size_delta + n;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
}

static bool	ft_deque_should_make_space_back(t_s_deque *deque, size_t n)
{
	return (deque->bottom <= n);
}

static void	ft_deque_ensure_space_back_bulk(t_s_deque *deque, size_t n)
{
	if (ft_deque_should_make_space_back(deque, n))
		ft_deque_grow_bottom_bulk(deque, n);
}

void	ft_deque_push_back_bulk(t_s_deque *deque, int *data, size_t n)
{
	if (!deque || !data)
		return ;
	ft_deque_ensure_space_back_bulk(deque, n);
	ft_memcpy(deque->data + deque->bottom - n, data, n * sizeof(*data));
	deque->bottom -= n;
	deque->size_actual += n;
}
