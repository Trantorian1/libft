/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:20:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:23:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_to_array.h"

#include "ft_memcpy.h"
#include "ft_malloc.h"

int	*ft_deque_to_array(t_s_deque *deque)
{
	int	*dst;
	int	*src;

	if (!deque)
		return (NULL);
	dst = ft_malloc(deque->size_actual * sizeof(*dst));
	if (!dst)
		return (NULL);
	src = deque->data + deque->bottom;
	ft_memcpy(dst, src, deque->size_actual * sizeof(*dst));
	return (dst);
}
