/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:34:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/06 18:14:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_swap.h"

#include "ft_error_handle.h"

int	ft_deque_swap(t_s_deque *deque)
{
	int	tmp;

	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM), 0);
	if (deque->size_actual <= 1)
		return (ft_error_throw(ERROR_SIZE), 0);
	tmp = deque->data[deque->top];
	deque->data[deque->top] = deque->data[deque->top - 1];
	deque->data[deque->top - 1] = tmp;
	return (0);
}
