/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/17 17:39:44 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_rotate.h"

#include "ft_memcpy.h"
#include "ft_malloc.h"
#include <stdbool.h>

static void	ft_deque_grow_back(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_new;

	size_new = deque->size_data * 2;
	new_array = ft_malloc(size_new * sizeof(*new_array));
	bottom_new = new_array + deque->size_data;
	ft_memcpy(bottom_new, deque->data, deque->size_actual * sizeof(*new_array));
	ft_free(deque->data);
	deque->data = new_array;
	deque->bottom = deque->size_data;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
}

static bool	ft_deque_should_grow_back(t_s_deque *deque)
{
	return (deque->bottom == 0);
}

static void	ft_deque_ensure_space_back(t_s_deque *deque)
{
	if (ft_deque_should_grow_back(deque))
		ft_deque_grow_back(deque);
}

void	ft_deque_rotate(t_s_deque *deque)
{
	if (!deque)
		return ;
	if (deque->bottom <= 1 || deque->top >= deque->size_data - 2)
		ft_deque_ensure_space_back(deque);
	deque->data[--deque->bottom] = deque->data[deque->top--];
}
