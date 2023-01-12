/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:46:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:33:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_reverse_rotate.h"

#include "ft_deque_ensure_space.h"
#include "errors.h"

/**
 * @brief Rotates the deque by one element toward the back.
 *
 * @param deque A pointer to the deque.
 *
 * @return 0 if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function works in a similar way to ft_deque_rotate(), except that it
 * shifts the element at the bottom of the deque to the top and increments the
 * top and bottom indices.
 */
int	ft_deque_reverse_rotate(t_s_deque *deque)
{
	if (deque->bottom <= 1 || deque->top >= deque->size_data - 2)
		if (ft_deque_ensure_space(deque))
			return (MALLOC_ERROR);
	deque->data[++deque->top] = deque->data[deque->bottom++];
	return (NO_ERROR);
}
