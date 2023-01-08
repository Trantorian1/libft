/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:28:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/08 18:27:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

static void	ft_dequeue_center(t_s_dequeue *deque)
{
	int		*bottom_old;
	int		*bottom_new;

	bottom_old = deque->data + deque->bottom;
	bottom_new = deque->data + (deque->size_data - deque->size_actual) / 2;
	ft_memmove(bottom_new, bottom_old, deque->size_actual);
}

/**
 * @brief Resizes the deque to twice its current size.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return NO_ERROR if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function allocates a new array with twice the size of the current deque
 * and copies the elements from the old array to the new array, centered in the
 * new array. It then updates the size of the deque and frees the old array.
 */
static int	ft_dequeue_grow(t_s_dequeue *dequeue)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = dequeue->size_data * 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	dequeue->size_data = size_new;
	bottom_old = dequeue->data + dequeue->bottom;
	bottom_new = new_array + (size_new - dequeue->size_actual) / 2;
	ft_memcpy(bottom_new, bottom_old, dequeue->size_actual);
	free(dequeue->data);
	dequeue->data = new_array;
	return (NO_ERROR);
}

/**
 * @brief Ensures that there is enough space in the deque for inserting an
 * element.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return NO_ERROR if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function checks if the deque needs to be resized by calling
 * ft_dequeue_should_make_space(). If the deque does not need to be resized, it
 * centers the elements in the deque by calling ft_dequeue_center(). If the
 * deque does need to be resized, it calls ft_dequeue_grow() to resize it.
 */
int	ft_dequeue_make_space(t_s_dequeue *dequeue)
{
	if (dequeue->size_actual < dequeue->size_data)
	{
		ft_dequeue_center(dequeue);
		return (NO_ERROR);
	}
	return (ft_dequeue_grow(dequeue));
}

/**
 * @brief Determines if the deque needs to be resized.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return true if the deque needs to be resized, false otherwise.
 *
 * The function checks if the bottom index is 0 or the top index is at the end
 * of the array. If either of these conditions is true, the deque needs to be
 * resized in order to insert an element.
 */
bool	ft_dequeue_should_make_space(t_s_dequeue *dequeue)
{
	return (dequeue->bottom = 0 || dequeue->top >= dequeue->size_data - 1);
}

/**
 * @brief Determines if the deque is empty.
 *
 * @param dequeue A pointer to the deque.
 *
 * @return true if the deque is empty, false otherwise.
 */
bool	ft_dequeue_is_empty(t_s_dequeue *dequeue)
{
	return (dequeue->size_actual <= 0);
}
