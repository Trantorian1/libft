/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:34:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/20 14:37:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_swap.h"

#include "errors.h"

int	ft_deque_swap(t_s_deque *deque)
{
	int	tmp;

	if (deque->size_actual <= 1)
		return (SIZE_ERROR);
	tmp = deque->data[deque->top];
	deque->data[deque->top] = deque->data[deque->top - 1];
	deque->data[deque->top - 1] = tmp;
	return (NO_ERROR);
}
