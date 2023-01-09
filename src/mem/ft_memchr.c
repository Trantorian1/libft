/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:10:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:16:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"

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
void	*ft_memchr(const void *src, int to_find, size_t n)
{
	size_t	i;

	i = 0;
	to_find = ft_tochar(to_find);
	while (i < n)
	{
		if (((t_byte *)src)[i] == to_find)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
