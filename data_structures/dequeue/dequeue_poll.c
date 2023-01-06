/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_poll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:13:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:18:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

int	ft_dequeue_poll_front(t_s_dequeue *dequeue)
{
	if (ft_dequeue_is_empty(dequeue))
		return (0);
	return (dequeue->data[dequeue->top]);
}

int	ft_dequeue_poll_back(t_s_dequeue *dequeue)
{
	if (ft_dequeue_is_empty(dequeue))
		return (0);
	return (dequeue->data[dequeue->bottom]);
}
