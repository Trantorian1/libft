/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 17:52:15 by emcnab           ###   ########.fr       */
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
	size_t		size_data;
	size_t		size_delta;
	int			*deque_array;

	deque = malloc(sizeof(*deque));
	if (!deque)
		return (NULL);
	size_data = ft_closest_power(size, 2);
	size_delta = (size_data - size) / 2;
	deque_array = malloc(size_data * sizeof(*deque_array));
	if (!deque_array)
		return ((void)(free(deque)), NULL);
	ft_memcpy(deque_array + size_delta, data, size * sizeof(*deque_array));
	deque->bottom = size_delta;
	deque->top = deque->bottom + size - 1;
	deque->size_data = size_data;
	deque->size_actual = size;
	deque->data = deque_array;
	return (deque);
}

void	*ft_deque_destroy(t_s_deque *deque, void (*f_free)(void *))
{
	deque->bottom = 0;
	deque->top = 0;
	f_free(deque->data);
	free(deque);
	return (NULL);
}
