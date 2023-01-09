/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:38:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

/*
 * @brief safer version of strncpy. Copies over at most size character from src
 * into dest, null-terminating the result.
 *
 * @param dest (char *): destination string in which to save the copy
 * @param src (char *): source string to be copied
 * @param maxlen (size_t): max number of bytes to copy.
 *
 * @return (size_t): size of dest if copy succeded (len(src)). Allows for easy
 * 	truncation detection by comparing the final length of dest to the returned
 * 	value of ft_strlcpy.
 */
size_t	ft_strlcpy(char *dest, t_str src, size_t maxlen)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < maxlen)
	{
		ft_memcpy(dest, src, srclen);
		dest[srclen] = '\0';
	}
	else if (maxlen != 0)
	{
		ft_memcpy(dest, src, maxlen - 1);
		dest[maxlen - 1] = '\0';
	}
	return (srclen);
}
