/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:01 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

/*
 * @brief Locates the first occurrence of the null-terminated string substr in 
 * the string source, where no more than n characters are searched
 *
 * @param source (t_str): parent string in which to locate the substring
 * @param substr (t_str): the substring to find in source
 * @param len (size_t): maximum number of characters to search.
 *
 * @return (char *):
 * 	- if substr is empty, returns source
 * 	- if substr is not a substring of source, returns NULL
 * 	- if substr is a substring of source, returns a pointer to the first 
 * 		character of substr in source
 */
char	*ft_strnstr(t_str source, t_str substr, size_t len)
{
	size_t	substr_len;

	substr_len = ft_strlen(substr);
	if (!substr_len)
		return ((char *)source);
	if (len == 0)
		return (NULL);
	while (*source && (len-- - substr_len + 1))
	{
		if (!ft_memcmp(source, substr, substr_len))
			return ((char *)source);
		source++;
	}
	return (NULL);
}
