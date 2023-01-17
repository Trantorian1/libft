/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_ensure_fit_back.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:09:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/17 19:23:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_ensure_fit_back.h"

#include <stdlib.h>
#include <stddef.h>
#include "errors.h"
#include "ft_memcpy.h"

static int	ft_deque_shrink_back(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;

	size_new = deque->size_data / 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	bottom_old = deque->data + deque->bottom;
	ft_memcpy(new_array, bottom_old, deque->size_actual * sizeof(*new_array));
	free(deque->data);
	deque->bottom = 0;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
	return (NO_ERROR);
}

static int	ft_deque_should_shrink_back(t_s_deque *deque)
{
	size_t	bottom_size;

	bottom_size = deque->size_data - deque->bottom;
	return (bottom_size < deque->size_data / SHRINK_FACTOR);
}

int	ft_deque_ensure_fit_back(t_s_deque *deque)
{
	if (!ft_deque_should_shrink_back(deque))
		return (NO_ERROR);
	return (ft_deque_shrink_back(deque));
}
