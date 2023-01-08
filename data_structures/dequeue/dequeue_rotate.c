/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:19:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/08 18:10:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

/**
 * @file dequeue_rotate.c
 *
 * @brief This file contains functions for rotating a deque
 * (double-ended queue).
 *
 * A deque is a dynamic array that allows insertions and deletions at both ends.
 * It has a front, a back, and a size.
 *
 * The functions are:
 * - ft_dequeue_rotate(): rotates the deque by one element toward the front.
 * - ft_dequeue_reverse_rotate(): rotates the deque by one element toward the
 *   back.
 *
 * @author Eliot McNab
 */

/**
 * @brief Rotates the deque by one element toward the front.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return 0 if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function first checks if the deque needs to be resized using the
 * ft_dequeue_make_space() function, and if it does, it returns MALLOC_ERROR if
 * the resize fails. Otherwise, it shifts the element at the top of the deque to
 * the bottom and decrements the top and bottom indices.
 */
int	ft_dequeue_rotate(t_s_dequeue *dequeue)
{
	if (dequeue->bottom <= 1 || dequeue->top >= dequeue->size_data - 2)
		if (ft_dequeue_make_space(dequeue))
			return (MALLOC_ERROR);
	dequeue->data[--dequeue->bottom] = dequeue->data[dequeue->top--];
	return (NO_ERROR);
}

/**
 * @brief Rotates the deque by one element toward the back.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return 0 if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function works in a similar way to ft_dequeue_rotate(), except that it
 * shifts the element at the bottom of the deque to the top and increments the
 * top and bottom indices.
 */
int	ft_dequeue_reverse_rotate(t_s_dequeue *dequeue)
{
	if (dequeue->bottom <= 1 || dequeue->top >= dequeue->size_data - 2)
		if (ft_dequeue_make_space(dequeue))
			return (MALLOC_ERROR);
	dequeue->data[++dequeue->top] = dequeue->data[dequeue->bottom++];
	return (NO_ERROR);
}
