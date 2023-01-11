/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:33:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 17:02:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memstr.h"

#include <stddef.h>
#include <stdint.h>
#include "ft_stralloc.h"
#include "ft_todigit.h"

/*
 * @brief Creates a string representation of a portion of system memory.
 *
 * @param mem (t_any): the memory to convert to string.
 * @param mem_size (size_t): the amount of bytes to represent in the string.
 *
 * @return (char *): string representation of the first [mem_size] bytes of
 * 	[mem].
 */
char	*ft_memstr(int8_t *mem, size_t mem_size)
{
	char	*str_mem;
	size_t	i;

	i = 0;
	str_mem = ft_stralloc(mem_size);
	if (!str_mem)
		return (NULL);
	while (i < mem_size)
	{
		str_mem[i] = ft_todigit(((int8_t *)mem)[i]);
		i++;
	}
	return (str_mem);
}
