/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:44:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/13 11:11:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_pop_front.h"

#include "ft_deque_is_empty.h"
#include "ft_memcpy.h"
#include "ft_error_handle.h"
#include <stdbool.h>
#include <stdlib.h>

static void	ft_deque_shrink_front(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data / 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (ft_error_throw(ERROR_MALLOC));
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + deque->bottom;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual * sizeof(*new_array));
	free(deque->data);
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
}

static bool	ft_deque_should_skrink_front(t_s_deque *deque)
{
	if (deque->size_data <= deque->size_min)
		return (false);
	return (deque->top < deque->size_data / SHRINK_FACTOR);
}

static void	ft_deque_ensure_fit_front(t_s_deque *deque)
{
	if (ft_deque_should_skrink_front(deque))
		ft_deque_shrink_front(deque);
}

int	ft_deque_pop_front(t_s_deque *deque)
{
	int	data;

	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM), 0);
	if (ft_deque_is_empty(deque))
		return (ft_error_throw(ERROR_SIZE), 0);
	deque->size_actual--;
	data = deque->data[deque->top--];
	ft_deque_ensure_fit_front(deque);
	if (ft_error_occurred())
		return (0);
	return (data);
}
