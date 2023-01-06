/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:28:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:16:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

static void	ft_dequeue_center(t_s_dequeue *dequeue)
{
	int		*bottom_old;
	int		*bottom_new;

	bottom_old = dequeue->data + dequeue->bottom;
	bottom_new = dequeue->data + (dequeue->size_data - dequeue->size_actual);
	ft_memmove(bottom_new, bottom_new, dequeue->size_actual);
}

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
	bottom_old = dequeue->data + dequeue->bottom;
	bottom_new = new_array + (size_new - dequeue->size_actual) / 2;
	ft_memcpy(bottom_new, bottom_old, dequeue->size_actual);
	free(dequeue->data);
	dequeue->data = new_array;
	return (NO_ERROR);
}

int	ft_dequeue_make_space(t_s_dequeue *dequeue)
{
	if (dequeue->size_actual < dequeue->size_data)
	{
		ft_dequeue_center(dequeue);
		return (NO_ERROR);
	}
	return (ft_dequeue_grow(dequeue));
}

bool	ft_dequeue_should_make_space(t_s_dequeue *dequeue)
{
	return (dequeue->bottom = 0 || dequeue->top >= dequeue->size_data - 1);
}

bool	ft_dequeue_is_empty(t_s_dequeue *dequeue)
{
	return (dequeue->size_actual <= 0);
}
