/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:25:25 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 18:32:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_size.h"
#include "ft_error_handle.h"

size_t	ft_deque_size(t_s_deque *deque)
{
	if (!deque)
		return ((void)(ft_error_throw(ERROR_NULL_PARAM)), 0);
	return (deque->size_actual);
}
