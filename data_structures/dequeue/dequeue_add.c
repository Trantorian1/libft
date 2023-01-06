/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:52:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:17:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

int	ft_dequeue_add_front(t_s_dequeue *dequeue, int n)
{
	if (ft_dequeue_should_make_space(dequeue) && ft_dequeue_make_space(dequeue))
		return (MALLOC_ERROR);
	dequeue->data[++dequeue->top] = n;
	dequeue->size_actual++;
	return (NO_ERROR);
}

int	ft_dequeue_add_back(t_s_dequeue *dequeue, int n)
{
	if (ft_dequeue_should_make_space(dequeue) && ft_dequeue_make_space(dequeue))
		return (MALLOC_ERROR);
	dequeue->data[--dequeue->bottom] = n;
	dequeue->size_actual++;
	return (NO_ERROR);
}
