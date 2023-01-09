/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:19:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:30:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/deque.h"

/**
 * @file deque_rotate.c
 *
 * @brief This file contains functions for rotating a deque
 * (double-ended queue).
 *
 * A deque is a dynamic array that allows insertions and deletions at both ends.
 * It has a front, a back, and a size.
 *
 * The functions are:
 * - ft_deque_rotate(): rotates the deque by one element toward the front.
 * - ft_deque_reverse_rotate(): rotates the deque by one element toward the
 *   back.
 *
 * @author Eliot McNab
 */

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
		if (ft_deque_make_space(deque))
			return (MALLOC_ERROR);
	deque->data[--deque->bottom] = deque->data[deque->top--];
	return (NO_ERROR);
}

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
		if (ft_deque_make_space(deque))
			return (MALLOC_ERROR);
	deque->data[++deque->top] = deque->data[deque->bottom++];
	return (NO_ERROR);
}
