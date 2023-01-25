/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:01:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 18:35:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_get.h"

#include "ft_array_is_empty.h"

int	ft_array_get(t_s_array *array, size_t index)
{
	return (array->data[index % array->index]);
}
