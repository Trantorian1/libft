/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:13:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_destroy.h"

#include "ft_malloc.h"

void	*ft_array_any_destroy(t_s_array_any *array, void (*f_free)(void *))
{
	size_t	i;

	if (!array)
		return (NULL);
	i = (size_t)(-1);
	if (f_free)
		while (++i < array->index)
			f_free((void *)array->data[i]);
	ft_free(array->data);
	ft_free(array);
	return (NULL);
}
