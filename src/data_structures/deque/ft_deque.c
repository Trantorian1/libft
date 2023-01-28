/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 17:11:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

#include <stdlib.h>
#include "ft_closest_power.h"
#include "ft_memcpy.h"
#include "ft_error_handle.h"

t_s_deque	*ft_deque_new(size_t size)
{
	t_s_deque	*deque;
	size_t		size_data;
	size_t		size_delta;
	int			*deque_array;

	deque = malloc(sizeof(*deque));
	if (!deque)
		return (ft_error_throw(ERROR_MALLOC), NULL);
	size_data = ft_closest_power(size, 2);
	size_delta = (size_data - size) / 2;
	deque_array = malloc(size_data * sizeof(*deque_array));
	if (!deque_array)
		return ((void)(free(deque)), ft_error_throw(ERROR_MALLOC), NULL);
	deque->bottom = size_delta;
	deque->top = deque->bottom - 1;
	deque->size_data = size_data;
	deque->size_actual = 0;
	deque->data = deque_array;
	return (deque);
}

void	*ft_deque_destroy(t_s_deque *deque, void (*f_free)(void *))
{
	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM), NULL);
	deque->bottom = 0;
	deque->top = 0;
	if (f_free)
		f_free(deque->data);
	free(deque);
	return (NULL);
}
