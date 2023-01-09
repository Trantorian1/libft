/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:33:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:16:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"

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
	if (((t_byte *)src) < ((t_byte *)dst))
		while (n--)
			((t_byte *)dst)[n] = ((t_byte *)src)[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
