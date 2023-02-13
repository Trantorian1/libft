/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:25:25 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/13 20:24:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_size.h"
#include "ft_error_handle.h"

size_t	ft_deque_size(t_s_deque *deque)
{
	return (deque->size_actual);
}
