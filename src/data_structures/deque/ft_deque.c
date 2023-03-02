/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:10:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

#include "ft_closest_power_ul.h"
#include "ft_memcpy.h"
#include "ft_malloc.h"

t_s_deque	*ft_deque_new(size_t size)
{
	t_s_deque	*deque;
	size_t		size_data;
	size_t		size_delta;
	int			*deque_array;

	deque = ft_malloc(sizeof(*deque));
	size_data = ft_closest_power_ul(size, 2);
	size_delta = (size_data - size) / 2;
	deque_array = ft_malloc(size_data * sizeof(*deque_array));
	deque->bottom = size_delta;
	deque->top = deque->bottom - 1;
	deque->size_data = size_data;
	deque->size_actual = 0;
	deque->size_min = size_data;
	deque->data = deque_array;
	return (deque);
}

void	*ft_deque_destroy(t_s_deque *deque, void (*f_free)(void *))
{
	if (!deque)
		return (NULL);
	deque->bottom = 0;
	deque->top = 0;
	if (f_free)
		f_free(deque->data);
	ft_free(deque);
	return (NULL);
}
