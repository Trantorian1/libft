/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:32:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_rotate.h"

#include "ft_deque_ensure_space.h"
#include "errors.h"

/**
 * @brief Rotates the deque by one element toward the front.
 *
 * @param deque A pointer to the deque.
 *
 * @return 0 if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function first checks if the deque needs to be resized using the
 * ft_deque_make_space() function, and if it does, it returns MALLOC_ERROR if
 * the resize fails. Otherwise, it shifts the element at the top of the deque to
 * the bottom and decrements the top and bottom indices.
 */
int	ft_deque_rotate(t_s_deque *deque)
{
	if (deque->bottom <= 1 || deque->top >= deque->size_data - 2)
		if (ft_deque_ensure_space(deque))
			return (MALLOC_ERROR);
	deque->data[--deque->bottom] = deque->data[deque->top--];
	return (NO_ERROR);
}
