/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:46:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:21:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_reverse_rotate.h"

#include "ft_memcpy.h"
#include "ft_malloc.h"
#include <stdbool.h>

static void	ft_deque_grow_top(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data * 2;
	new_array = ft_malloc(size_new * sizeof(*new_array));
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + deque->bottom;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual * sizeof(*new_array));
	ft_free(deque->data);
	deque->data = new_array;
	deque->size_data = size_new;
}

static bool	ft_deque_should_grow_top(t_s_deque *deque)
{
	return (deque->top == deque->size_data - 1);
}

static void	ft_deque_ensure_space_top(t_s_deque *deque)
{
	if (ft_deque_should_grow_top(deque))
		ft_deque_grow_top(deque);
}

void	ft_deque_reverse_rotate(t_s_deque *deque)
{
	if (!deque)
		return ;
	if (deque->bottom <= 1 || deque->top >= deque->size_data - 2)
		ft_deque_ensure_space_top(deque);
	deque->data[++deque->top] = deque->data[deque->bottom++];
}
