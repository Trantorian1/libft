/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:41:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 18:31:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_push_front.h"

#include "ft_deque_ensure_space_top.h"
#include "ft_memcpy.h"
#include "ft_error_handle.h"
#include <stdlib.h>

static void	ft_deque_grow_top(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data * 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (ft_error_throw(ERROR_MALLOC));
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + deque->bottom;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual * sizeof(*new_array));
	free(deque->data);
	deque->data = new_array;
	deque->size_data = size_new;
}

static bool	ft_deque_should_grow_top(t_s_deque *deque)
{
	return (deque->top == deque->size_data - 1);
}

void	ft_deque_ensure_space_top(t_s_deque *deque)
{
	if (ft_deque_should_grow_top(deque))	
		ft_deque_grow_top(deque);
}

void	ft_deque_push_front(t_s_deque *deque, int n)
{
	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM));
	ft_deque_ensure_space_top(deque);
	if (ft_error_occurred())
		return ;
	deque->data[++deque->top] = n;
	deque->size_actual++;
}
