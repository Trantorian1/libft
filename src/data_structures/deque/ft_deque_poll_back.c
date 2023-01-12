/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:43:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:31:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_back.h"

#include "ft_deque_is_empty.h"

/**
 * @brief Retrieves the element at the back of the deque without removing it.
 *
 * @param deque A pointer to the deque.
 *
 * @return The element at the back of the deque, or 0 if the deque is empty.
 *
 * The function works in a similar way to ft_deque_poll_front(), except that
 * it returns the element at the back of the deque, which is stored in the
 * deque's data array at the bottom index.
 */
int	ft_deque_poll_back(t_s_deque *deque)
{
	if (ft_deque_is_empty(deque))
		return (0);
	return (deque->data[deque->bottom]);
}
