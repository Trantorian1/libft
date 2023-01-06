/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:57:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:17:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

int	ft_dequeue_pop_front(t_s_dequeue *dequeue)
{
	if (ft_dequeue_is_empty(dequeue))
		return (0);
	dequeue->size_actual--;
	return (dequeue->data[dequeue->top--]);
}

int	ft_dequeue_pop_back(t_s_dequeue *dequeue)
{
	if (ft_dequeue_is_empty(dequeue))
		return (0);
	dequeue->size_actual--;
	return (dequeue->data[dequeue->bottom++]);
}
