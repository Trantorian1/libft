/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push_front_bulk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:38:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:19:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_push_front_bulk.h"

#include "ft_closest_power_ul.h"
#include "ft_memcpy.h"
#include "ft_malloc.h"
#include <stdbool.h>

static void	ft_deque_grow_top_bulk(t_s_deque *deque, size_t n)
{
	size_t	size_new;
	size_t	size_delta;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = ft_closest_power_ul(deque->size_data + n, 2);
	size_delta = (size_new - deque->size_actual - n) / 2;
	new_array = ft_malloc(size_new * sizeof(*new_array));
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + size_delta;
	ft_memcpy(
		bottom_new, bottom_old,
		deque->size_actual * sizeof(*new_array));
	ft_free(deque->data);
	deque->bottom = size_delta;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
}

static bool	ft_deque_should_make_space_top(t_s_deque *deque, size_t n)
{
	return (deque->top + n > deque->size_data - 1);
}

static void	ft_deque_ensure_space_top_bulk(t_s_deque *deque, size_t n)
{
	if (ft_deque_should_make_space_top(deque, n))
		ft_deque_grow_top_bulk(deque, n);
}

void	ft_deque_push_front_bulk(t_s_deque *deque, int *data, size_t n)
{
	if (!deque || !data)
		return ;
	ft_deque_ensure_space_top_bulk(deque, n);
	ft_memcpy(deque->data + deque->top + 1, data, n * sizeof(*data));
	deque->top += n;
	deque->size_actual += n;
}
