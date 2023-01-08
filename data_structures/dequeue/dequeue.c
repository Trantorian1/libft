/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:17:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/08 17:23:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

/**
 * @file dequeue.c
 *
 * @brief This file contains functions for creating and destroying a deque
 * (double-ended queue).
 *
 * A deque is a dynamic array that allows insertions and deletions at both ends.
 * It has a front, a back, and a size.
 *
 * The functions are:
 * - ft_dequeue_new(): creates and returns a new deque with the given data and
 *   size.
 * - ft_dequeue_destroy(): frees the memory used by the given deque.
 *
 * @author Eliot McNab
 */

/**
 * @brief Creates and returns a new deque with the given data and size.
 *
 * @param data Pointer to the array with the data to be stored in the deque.
 * @param size The size of the data array.
 *
 * @return A pointer to the new deque, or NULL if an error occurs.
 *
 * The function first allocates memory for the deque struct and initializes its
 * fields. It then allocates memory for the data array and copies the given data
 * into it. The ft_closest_power() function is used to find the closest power of
 * 2 to the size, and the ft_memcpy() function is used to copy the data from the
 * input array to the deque's data array.
 */
t_s_dequeue	*ft_dequeue_new(int *data, size_t size)
{
	t_s_dequeue	*dequeue;
	size_t		size_dequeue;
	size_t		size_delta;
	int			*dequeue_array;

	dequeue = malloc(sizeof(*dequeue));
	if (!dequeue)
		return (NULL);
	size_dequeue = ft_closest_power(size, 2);
	size_delta = (size_dequeue - size) / 2;
	dequeue_array = malloc(size * sizeof(*dequeue_array));
	if (!dequeue_array)
		return (free(dequeue), NULL);
	ft_memcpy(dequeue_array + size_delta, data, size * sizeof(*dequeue_array));
	dequeue->bottom = size / 2;
	dequeue->top = dequeue->bottom + 1;
	dequeue->size_data = size_dequeue;
	dequeue->size_actual = size;
	dequeue->data = dequeue_array;
	return (dequeue);
}

/**
 * @brief Destroys a dequeue and frees its memory.
 * 
 * @param dequeue (t_s_dequeue *): The dequeue to be destroyed.
 *
 * @return (void *): A NULL pointer.
 */
void	*ft_dequeue_destroy(t_s_dequeue *dequeue)
{
	dequeue->bottom = 0;
	dequeue->top = 0;
	free(dequeue->data);
	free(dequeue);
	return (NULL);
}
