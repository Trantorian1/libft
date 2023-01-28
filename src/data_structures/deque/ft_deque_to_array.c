/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:20:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 19:00:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_to_array.h"

#include "ft_memcpy.h"
#include "ft_error_handle.h"
#include <stdlib.h>

int	*ft_deque_to_array(t_s_deque *deque)
{
	int	*dst;
	int	*src;

	if (!deque)
		return (ft_error_throw(ERROR_NULL_PARAM), NULL);
	dst = malloc(deque->size_actual * sizeof(*dst));
	if (!dst)
		return (ft_error_throw(ERROR_NULL_PARAM), NULL);
	src = deque->data + deque->bottom;
	ft_memcpy(dst, src, deque->size_actual * sizeof(*dst));
	return (dst);
}
