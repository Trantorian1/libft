/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:23:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/18 12:32:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memcmp.h"

#include <stddef.h>
#include <stdint.h>

/*
 * @brief compares two areas of memory.
 *
 * @param mem_a (const void *): the first area of memory.
 * @param mem_b (const void *): the second area of memory.
 * @param n (size_t): the number of bytes to compare.
 *
 * @return (int): difference between the bytes in mem_a and mem_b.
 * 	- 0 if mem_a and mem_b contain the same byte values.
 * 	- < 0 if the sum of the n first bytes in mem_a is smaller than the sum of 
 * 		all bytes in mem_b.
 *	- > 0 if the sum of the n first bytes in mem_a is greater than the sum of
 *		all bytes in mem_b.
 */
int	ft_memcmp(const void *mem_a, const void *mem_b, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (((const int8_t *)mem_a)[i] != ((const int8_t *)mem_b)[i])
			return (((const int8_t *)mem_a)[i] - ((const int8_t *)mem_b)[i]);
		i++;
	}
	return (0);
}
