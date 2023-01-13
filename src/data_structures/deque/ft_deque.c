/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 16:55:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

#include <stdlib.h>
#include "ft_closest_power.h"
#include "ft_memcpy.h"

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
t_s_deque	*ft_deque_new(int *data, size_t size)
{
	t_s_deque	*deque;
	size_t		size_deque;
	size_t		size_delta;
	int			*deque_array;

	deque = malloc(sizeof(*deque));
	if (!deque)
		return (NULL);
	size_deque = ft_closest_power(size, 2);
	size_delta = (size_deque - size) / 2;
	deque_array = malloc(size_deque * sizeof(*deque_array));
	if (!deque_array)
		return ((void)(free(deque)), NULL);
	ft_memcpy(deque_array + size_delta, data, size * sizeof(*deque_array));
	deque->bottom = size / 2;
	deque->top = deque->bottom + 1;
	deque->size_data = size_deque;
	deque->size_actual = size;
	deque->data = deque_array;
	return (deque);
}

/**
 * @brief Destroys a deque and frees its memory.
 * 
 * @param deque (t_s_deque *): The deque to be destroyed.
 *
 * @return (void *): A NULL pointer.
 */
void	*ft_deque_destroy(t_s_deque *deque)
{
	deque->bottom = 0;
	deque->top = 0;
	free(deque->data);
	free(deque);
	return (NULL);
}
