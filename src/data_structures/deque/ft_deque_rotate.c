/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 18:56:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_rotate.h"

#include "ft_deque_ensure_space.h"
#include "ft_error_handle.h"

// TODO: implement optimised version of ft_deque_ensure_space here
void	ft_deque_rotate(t_s_deque *deque)
{
	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM));
	if (deque->bottom <= 1 || deque->top >= deque->size_data - 2)
	{
		ft_deque_ensure_space(deque);
		if (ft_error_occurred())
			return ;
	}
	deque->data[--deque->bottom] = deque->data[deque->top--];
}
