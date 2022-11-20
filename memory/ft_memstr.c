/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:33:51 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:04:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Creates a string representation of a portion of system memory.
 *
 * @param mem (t_any): the memory to convert to string.
 * @param mem_size (size_t): the amount of bytes to represent in the string.
 *
 * @return (char *): string representation of the first [mem_size] bytes of
 * 	[mem].
 */
char	*ft_memstr(t_any mem, size_t mem_size)
{
	char	*str_mem;
	size_t	i = 0;

	if (!(str_mem = ft_stralloc(mem_size)))
		return (NULL);
	while (i < mem_size)
	{
		str_mem[i] = ft_todigit(((t_byte *)mem)[i]);
		i++;
	}
	return (str_mem);
}
