/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:01:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/26 16:14:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_get.h"

#include "ft_error_handle.h"

void	*ft_array_any_get(t_s_array_any *array, size_t index)
{
	if (!array)
		return (NULL);
	return ((void *)array->data[index % array->index]);
}
