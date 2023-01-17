/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_ensure_space_top.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:32:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/17 18:46:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_ensure_space_top.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "errors.h"
#include "ft_memcpy.h"

static int	ft_deque_grow_top(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data * 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + deque->bottom;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual * sizeof(*new_array));
	free(deque->data);
	deque->data = new_array;
	deque->size_data = size_new;
	return (NO_ERROR);
}

static bool	ft_deque_should_grow_top(t_s_deque *deque)
{
	return (deque->top == deque->size_data - 1);
}

int	ft_deque_ensure_space_top(t_s_deque *deque)
{
	if (!ft_deque_should_grow_top(deque))	
		return (NO_ERROR);
	return (ft_deque_grow_top(deque));
}
