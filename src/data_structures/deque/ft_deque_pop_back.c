/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:13:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_pop_back.h"

#include "e_error.h"
#include "ft_deque_is_empty.h"
#include "ft_memcpy.h"
#include "ft_malloc.h"
#include <stdbool.h>

static void	ft_deque_shrink_back(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;

	size_new = deque->size_data / 2;
	new_array = ft_malloc(size_new * sizeof(*new_array));
	bottom_old = deque->data + deque->bottom;
	ft_memcpy(new_array, bottom_old, deque->size_actual * sizeof(*new_array));
	ft_free(deque->data);
	deque->bottom = 0;
	deque->top = deque->bottom + deque->size_actual - 1;
	deque->size_data = size_new;
	deque->data = new_array;
}

static bool	ft_deque_should_shrink_back(t_s_deque *deque)
{
	size_t	bottom_size;

	if (deque->size_data <= deque->size_min)
		return (false);
	bottom_size = deque->size_data - deque->bottom;
	return (bottom_size < deque->size_data / SHRINK_FACTOR);
}

static void	ft_deque_ensure_fit_back(t_s_deque *deque)
{
	if (ft_deque_should_shrink_back(deque))
		ft_deque_shrink_back(deque);
}

/**
 * @brief Retrieves and removes the element at the back of the deque.
 *
 * @param deque A pointer to the deque.
 *
 * @return The element at the back of the deque, or 0 if the deque is empty.
 *
 * The function works in a similar way to ft_deque_pop_front(), except that
 * it returns the element at the back of the deque, which is stored in the
 * deque's data array at the bottom index. It then increments the bottom index.
 */
int	ft_deque_pop_back(t_s_deque *deque)
{
	int	data;

	if (!deque)
		return (0);
	if (ft_deque_is_empty(deque))
		return (0);
	ft_deque_ensure_fit_back(deque);
	deque->size_actual--;
	data = deque->data[deque->bottom++];
	return (data);
}
