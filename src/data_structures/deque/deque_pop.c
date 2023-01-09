/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:57:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:30:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/deque.h"

/**
 * @file deque_pop.c
 *
 * @brief This file contains functions for popping elements from a deque
 * (double-ended queue).
 *
 * A deque is a dynamic array that allows insertions and deletions at both ends.
 * It has a front, a back, and a size.
 *
 * The functions are:
 * - ft_deque_pop_front(): retrieves and removes the element at the front of
 *   the deque.
 * - ft_deque_pop_back(): retrieves and removes the element at the back of
 *   the deque.
 *
 * @author Eliot McNab
 */

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

/**
 * @brief Retrieves and removes the element at the back of the deque.
 *
 * @param deque A pointer to the deque.
 *
 * @return The element at the back of the deque, or 0 if the deque is empty.
 *
 * The function works in a similar way to ft_deque_pop_front(), except that
 * it returns the element at the back of the deque, which is stored in the
 * deque's data array at the bottom index. It then increments the bottom index.
 */
int	ft_deque_pop_back(t_s_deque *deque)
{
	if (ft_deque_is_empty(deque))
		return (0);
	deque->size_actual--;
	return (deque->data[deque->bottom++]);
}
