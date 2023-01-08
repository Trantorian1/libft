/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:52:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/08 18:29:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

/**
 * @file dequeue_add.c
 *
 * @brief This file contains functions for adding elements to a deque
 * (double-ended queue).
 *
 * A deque is a dynamic array that allows insertions and deletions at both ends.
 * It has a front, a back, and a size.
 *
 * The functions are:
 * - ft_dequeue_add_front(): adds an element to the front of the deque.
 * - ft_dequeue_add_back(): adds an element to the back of the deque.
 *
 * @author Eliot McNab
 */

/**
 * @brief Adds an element to the front of the deque.
 *
 * @param dequeue A pointer to the deque.
 * @param n The element to be added.
 *
 * @return NO_ERROR if the element was successfully added, MALLOC_ERROR if an
 * error occurred.
 *
 * The function first checks if the deque needs to make space using the
 * ft_dequeue_should_make_space() function, and if it does, it calls the 
 * ft_dequeue_make_space() function to do so. If either function returns an
 * error, the function returns MALLOC_ERROR. Otherwise, it adds the element to
 * the front of the deque by incrementing the top index and storing the element
 * in the deque's data array at that index. It then increments the size of the
 * deque.
 */
int	ft_dequeue_add_front(t_s_dequeue *dequeue, int n)
{
	if (ft_dequeue_should_make_space(dequeue) && ft_dequeue_make_space(dequeue))
		return (MALLOC_ERROR);
	dequeue->data[++dequeue->top] = n;
	dequeue->size_actual++;
	return (NO_ERROR);
}

/**
 * @brief Adds an element to the back of the deque.
 *
 * @param dequeue A pointer to the deque.
 * @param n The element to be added.
 *
 * @return NO_ERROR if the element was successfully added, MALLOC_ERROR if an
 * error occurred.
 *
 * The function works in a similar way to ft_dequeue_add_front(), except that
 * it decrements the bottom index instead of incrementing the top index, and
 * adds the element to the back of the deque by storing it in the deque's data
 * array at that index.
 */
int	ft_dequeue_add_back(t_s_dequeue *dequeue, int n)
{
	if (ft_dequeue_should_make_space(dequeue) && ft_dequeue_make_space(dequeue))
		return (MALLOC_ERROR);
	dequeue->data[--dequeue->bottom] = n;
	dequeue->size_actual++;
	return (NO_ERROR);
}
