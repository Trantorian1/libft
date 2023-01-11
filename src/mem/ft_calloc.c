/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:29:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 17:02:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calloc.h"

#include <stddef.h>
#include <stdlib.h>
#include "ft_bzero.h"

/*
 * @brief Allocates memory for an array of elem_count elements which each take
 * 	elem_size bytes in memory.
 *
 * @param elem_count (size_t): number of elements in the array.
 * @oaram elem_size (size_t): size, in bytes, of each element in memory.
 *
 * @return (void *): array with memory allocated for elem_count elements.
 */
void	*ft_calloc(size_t elem_count, size_t elem_size)
{
	void	*memory;

	memory = malloc(elem_count * elem_size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, elem_count * elem_size);
	return (memory);
}
