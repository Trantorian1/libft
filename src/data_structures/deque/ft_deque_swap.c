/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:34:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:23:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_swap.h"

int	ft_deque_swap(t_s_deque *deque)
{
	int	tmp;

	if (!deque)
		return (0);
	if (deque->size_actual <= 1)
		return (0);
	tmp = deque->data[deque->top];
	deque->data[deque->top] = deque->data[deque->top - 1];
	deque->data[deque->top - 1] = tmp;
	return (0);
}
