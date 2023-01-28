/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:43:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 18:44:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_back.h"

#include "ft_deque_is_empty.h"
#include "ft_error_handle.h"

int	ft_deque_poll_back(t_s_deque *deque)
{
	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM), 0);
	if (ft_deque_is_empty(deque))
		return (ft_error_throw(ERROR_SIZE), 0);
	return (deque->data[deque->bottom]);
}
