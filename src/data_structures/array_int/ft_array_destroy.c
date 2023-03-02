/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:09:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_destroy.h"
#include "ft_malloc.h"

void	*ft_array_destroy(t_s_array *array)
{
	ft_free(array->data);
	ft_free(array);
	return (NULL);
}
