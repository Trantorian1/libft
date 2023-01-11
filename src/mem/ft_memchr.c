/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:10:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:58:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memchr.h"

#include <stddef.h>
#include <stdint.h>

/*
 * @brief Scans the first n bytes of the memory area pointed to by src for the 
 * 	first instance of to_find.
 *
 * @param src (const void *): area in memory to scan.
 * @param to_find (int): byte to find in src.
 *
 * @return (void *): the first occurence of to_find in the initial n bytes of
 * src, or NULL if no instance of to_find was found.
 */
void	*ft_memchr(const void *src, int8_t to_find, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((int8_t *)src)[i] == to_find)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
