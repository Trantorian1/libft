/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:14:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:16:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"

/*
 * @brief copies n bytes from memory area src to memory area dest. The memory 
 * areas must not overlap.
 *
 * @param dest (void *): area in memory to copy bytes over to.
 * @param src (const void *): area in memory from which to copy the bytes.
 * @param n (size_t): number of bytes to copy over.
 *
 * @return (void *): the adress in memory where the bytes were copied.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((t_byte *)dest)[i] = ((const t_byte *)src)[i];
		i++;
	}
	return (dest);
}
