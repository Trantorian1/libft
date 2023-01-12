/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:41:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:00:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_add_back.h"

#include "ft_deque_ensure_space.h"
#include "errors.h"

/**
 * @brief Adds an element to the back of the deque.
 *
 * @param deque A pointer to the deque.
 * @param n The element to be added.
 *
 * @return NO_ERROR if the element was successfully added, MALLOC_ERROR if an
 * error occurred.
 *
 * The function works in a similar way to ft_deque_add_front(), except that
 * it decrements the bottom index instead of incrementing the top index, and
 * adds the element to the back of the deque by storing it in the deque's data
 * array at that index.
 */
int	ft_deque_add_back(t_s_deque *deque, int n)
{
	if (ft_deque_ensure_space(deque))
		return (MALLOC_ERROR);
	deque->data[--deque->bottom] = n;
	deque->size_actual++;
	return (NO_ERROR);
}
