/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/27 14:03:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_any_destroy.h"

#include "ft_error_handle.h"
#include <stdlib.h>

void	*ft_array_any_destroy(t_s_array_any *array, void (*f_free)(void *))
{
	size_t	i;

	if (!array)
		return (NULL);
	i = (size_t)(-1);
	if (f_free)
		while (++i < array->index)
			f_free(array->data[i]);
	free(array->data);
	free(array);
	return (NULL);
}
