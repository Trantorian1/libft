/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:43:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:11:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_front.h"

#include "ft_deque_is_empty.h"
#include "ft_deque_size.h"

/**
 * @brief Retrieves the element at the front of the deque without removing it.
 *
 * @param deque A pointer to the deque.
 *
 * @return The element at the front of the deque, or 0 if the deque is empty.
 *
 * The function first checks if the deque is empty using the
 * ft_deque_is_empty() function, and if it is, it returns 0. Otherwise,
 * it returns the element at the front of the deque, which is stored in the
 * deque's data array at the top index.
 */
int	ft_deque_poll_front(t_s_deque *deque)
{
	if (ft_deque_size(deque) == 0)
		return (0);
	return (deque->data[deque->top]);
}
