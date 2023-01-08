/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:57:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/08 18:01:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

/**
 * @file dequeue_pop.c
 *
 * @brief This file contains functions for popping elements from a deque
 * (double-ended queue).
 *
 * A deque is a dynamic array that allows insertions and deletions at both ends.
 * It has a front, a back, and a size.
 *
 * The functions are:
 * - ft_dequeue_pop_front(): retrieves and removes the element at the front of
 *   the deque.
 * - ft_dequeue_pop_back(): retrieves and removes the element at the back of
 *   the deque.
 *
 * @author Eliot McNab
 */

/**
 * @brief Retrieves and removes the element at the front of the deque.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return The element at the front of the deque, or 0 if the deque is empty.
 *
 * The function first checks if the deque is empty using the
 * ft_dequeue_is_empty() function, and if it is, it returns 0. Otherwise, it
 * decrements the size of the deque and returns the element at the front of
 * the deque, which is stored in the deque's data array at the top index. It
 * then decrements the top index.
 */
int	ft_dequeue_pop_front(t_s_dequeue *dequeue)
{
	if (ft_dequeue_is_empty(dequeue))
		return (0);
	dequeue->size_actual--;
	return (dequeue->data[dequeue->top--]);
}

/**
 * @brief Retrieves and removes the element at the back of the deque.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return The element at the back of the deque, or 0 if the deque is empty.
 *
 * The function works in a similar way to ft_dequeue_pop_front(), except that
 * it returns the element at the back of the deque, which is stored in the
 * deque's data array at the bottom index. It then increments the bottom index.
 */
int	ft_dequeue_pop_back(t_s_dequeue *dequeue)
{
	if (ft_dequeue_is_empty(dequeue))
		return (0);
	dequeue->size_actual--;
	return (dequeue->data[dequeue->bottom++]);
}
