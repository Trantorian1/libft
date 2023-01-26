/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 14:50:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_destroy.h"

#include <stdlib.h>

void	*ft_array_destroy(t_s_array *array)
{
	free(array->data);
	free(array);
	return (NULL);
}
