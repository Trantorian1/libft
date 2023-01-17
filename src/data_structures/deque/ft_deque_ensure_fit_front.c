/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_ensure_fit_front.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:26:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/17 17:38:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_ensure_fit_front.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "errors.h"
#include "ft_memcpy.h"

static int	ft_deque_shrink_front(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data / 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + deque->bottom;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual * sizeof(*new_array));
	free(deque->data);
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
	return (NO_ERROR);
}

static bool	ft_deque_should_skrink_front(t_s_deque *deque)
{
	return (deque->top < deque->size_data / SHRINK_FACTOR);
}

int	ft_deque_ensure_fit_front(t_s_deque *deque)
{
	if (!ft_deque_should_skrink_front(deque))
		return (NO_ERROR);
	return (ft_deque_shrink_front(deque));
}
