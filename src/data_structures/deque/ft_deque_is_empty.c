/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_is_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:11:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_is_empty.h"

/**
 * @brief Determines if the deque is empty.
 *
 * @param deque A pointer to the deque.
 *
 * @return true if the deque is empty, false otherwise.
 */
bool	ft_deque_is_empty(t_s_deque *deque)
{
	if (!deque)
		return (true);
	return (deque->size_actual <= 0);
}
