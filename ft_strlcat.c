/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:52:11 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/16 12:59:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static char	*ft_goto_end(char *dest, size_t size)
{
	while (size-- && *dest)
	{
		dest++;
	}
	return (dest);
}

/*
 * @brief safer version of strncat which guarantees null-termination. Tries to 
 * concatenate the contents of src at the end of dest. This worlks like strncat. 
 * but the total size of the buffer is known, including space for the null-byte.
 * If there is not enough space for concatenation, stops at [size] characters
 * and null-terminates the result. This guarantees that the resulting
 * concatenation can only be at most size-1 characters long.
 *
 * @param dest (char *): null-terminated destination string where the 
 * 	concatenation is stored.
 * @param scr (t_str): null-terminated string to be concatenated at the end of
 * 	dest.
 *
 * @return (size_t): who tf even knows the logic behind this bullshit...
 */
size_t	ft_strlcat(char *dest, t_str src, size_t size)
{
	char	*dest_cpy;
	size_t	size_cpy;
	size_t	dest_len;
	t_str	src_cpy;

	dest_cpy = ft_goto_end(dest, size);
	dest_len = dest_cpy - dest;
	size_cpy = size - dest_len;
	if (size_cpy-- == 0)
	{
		return (dest_len + ft_strlen(src));
	}
	src_cpy = src;
	while (*src_cpy)
	{
		if (size_cpy > 0)
		{
			*dest_cpy++ = *src_cpy;
			size_cpy--;
		}
		src_cpy++;
	}
	*dest_cpy = '\0';
	return (dest_len + src_cpy - src);
}
