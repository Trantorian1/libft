/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/17 17:54:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_pop_back.h"

#include "ft_deque_is_empty.h"
#include "ft_deque_ensure_fit_back.h"

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
	int	data;
	int	error_code;

	if (ft_deque_is_empty(deque))
		return (0);
	deque->size_actual--;
	data = deque->data[deque->bottom++];
	error_code = ft_deque_ensure_fit_back(deque);
	if (error_code)
		return (error_code);
	return (data);
}
