/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:44:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:31:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_pop_front.h"

#include "ft_deque_is_empty.h"

/**
 * @brief Retrieves and removes the element at the front of the deque.
 *
 * @param deque A pointer to the deque.
 *
 * @return The element at the front of the deque, or 0 if the deque is empty.
 *
 * The function first checks if the deque is empty using the
 * ft_deque_is_empty() function, and if it is, it returns 0. Otherwise, it
 * decrements the size of the deque and returns the element at the front of
 * the deque, which is stored in the deque's data array at the top index. It
 * then decrements the top index.
 */
int	ft_deque_pop_front(t_s_deque *deque)
{
	if (ft_deque_is_empty(deque))
		return (0);
	deque->size_actual--;
	return (deque->data[deque->top--]);
}
