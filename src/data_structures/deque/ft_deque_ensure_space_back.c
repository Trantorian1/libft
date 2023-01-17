/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_ensure_space_back.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:55:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/17 19:05:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_deque.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "errors.h"
#include "ft_memcpy.h"

static int	ft_deque_grow_back(t_s_deque *deque)
{
	size_t	size_new;
	size_t	size_delta;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data * 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	size_delta = size_new - (deque->size_data - deque->bottom);
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + size_delta;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual * sizeof(new_array));
	free(deque->data);
	deque->data = new_array;
	deque->bottom = size_delta;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	return (NO_ERROR);
}

static bool	ft_deque_should_grow_back(t_s_deque *deque)
{
	return (deque->bottom == 0);
}

int	ft_deque_ensure_space_back(t_s_deque *deque)
{
	if (!ft_deque_should_grow_back(deque))
		return (NO_ERROR);
	return (ft_deque_grow_back(deque));
}
