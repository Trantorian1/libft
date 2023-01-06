/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:17:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:14:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

t_s_dequeue	*ft_dequeue_new(int *data, size_t size)
{
	t_s_dequeue	*dequeue;
	t_s_bounds	*bounds;
	size_t		dequeue_size;
	size_t		delta_size;
	int			*dequeue_array;

	dequeue = malloc(sizeof(*dequeue));
	if (!dequeue)
		return (NULL);
	dequeue_size = ft_closest_power(size, 2);
	delta_size = (dequeue_size - size) / 2;
	dequeue_array = malloc(size * sizeof(*dequeue_array));
	if (!dequeue_array)
		return (free(dequeue), NULL);
	ft_memcpy(dequeue_array + delta_size, data, size * sizeof(*dequeue_array));
	dequeue->bottom = size / 2;
	dequeue->top = dequeue->bottom + 1;
	dequeue->size_data = size;
	dequeue->size_actual = 0;
	dequeue->data = dequeue_array;
	return (dequeue);
}

void	*ft_dequeue_destroy(t_s_dequeue *dequeue)
{
	dequeue->bottom = 0;
	dequeue->top = 0;
	free(dequeue->data);
	free(dequeue);
	return (NULL);
}
