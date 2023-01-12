/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:43:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:34:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_destroy.h"

#include <stdlib.h>

/**
 * @brief Destroys a deque and frees its memory.
 * 
 * @param deque (t_s_deque *): The deque to be destroyed.
 *
 * @return (void *): A NULL pointer.
 */
void	*ft_deque_destroy(t_s_deque *deque)
{
	deque->bottom = 0;
	deque->top = 0;
	free(deque->data);
	free(deque);
	return (NULL);
}
