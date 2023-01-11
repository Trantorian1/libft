/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:33:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 17:02:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memmove.h"

#include <stddef.h>
#include <stdint.h>
#include "ft_memcpy.h"

/*
 * @brief copies n bytes from memory area src to memory area dest.
 * 	The memory areas may overlap.
 *
 * @param dest (void *): area in memory to which bytes will be copied
 * 	to.
 * @param src (const void *): area in memory from which to copy the bytes.
 * @param n (size_t): amount of bytes of memory to copy.
 *
 * @return (void *): pointer to the area in memory where data was copied.
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (((int8_t *)src) < ((int8_t *)dst))
		while (n--)
			((int8_t *)dst)[n] = ((int8_t *)src)[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
