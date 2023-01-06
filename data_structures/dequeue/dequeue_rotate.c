/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:19:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:54:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

int	ft_dequeue_rotate(t_s_dequeue *dequeue)
{
	if (dequeue->bottom <= 1 || dequeue->top >= dequeue->size_data - 2)
		if (ft_dequeue_make_space(dequeue))
			return (MALLOC_ERROR);
	dequeue->data[--dequeue->bottom] = dequeue->data[dequeue->top--];
	return (NO_ERROR);
}

int	ft_dequeue_reverse_rotate(t_s_dequeue *dequeue)
{
	if (dequeue->bottom <= 1 || dequeue->top >= dequeue->size_data - 2)
		if (ft_dequeue_make_space(dequeue))
			return (MALLOC_ERROR);
	dequeue->data[++dequeue->top] = dequeue->data[dequeue->bottom++];
	return (NO_ERROR);
}
