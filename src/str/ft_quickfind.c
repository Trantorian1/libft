/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quickfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

static bool	ft_isalinged(const char *str)
{
	return (!((t_lword)(str) & (sizeof(t_lword) - 1)));
}

static const char	*ft_memalign(const char *str, char to_find)
{
	size_t	i;

	i = 0;
	while (!ft_isalinged(str + i) && str[i] && str[i] != to_find)
		i++;
	return (str + i);
}

// _Pragma("GCC diagnostic push")
// _Pragma("GCC diagnostic ignored \"-Wcast-align\"")

/*
 * @brief Rapidly searches for a character [c] in a string [str].
 *
 * Takes advantage of longwords to compare as many bytes as possible. Support
 * any c longbyte implementation.
 *
 * Searching is done by first aligning [str] to the size of a longword in the
 * current C implementation and then searching for [c] one longword at a time
 * instead of one byte at a time. Since c standard defines long as containing
 * at least 32 bits, or 4 bytes, this approach is at least 4x as fast as 
 * standard linear search. On implementations which support 64bit or more 
 * longwords, this increase is even more noticeable.
 *
 * @param str (char *): the string to search.
 * @param c (int): the character to find, considered as an unsigned char.
 *
 * @return (char *): pointer to the first occurenceof [c] in [str], or to the
 *         terminating null-byte at the end of [str] if [c] was not found.
 */
const char	*ft_quickfind(const char *str, char to_find)
{
	size_t	i;

	str = ft_memalign(str, to_find);
	if (!ft_isalinged(str))
		return (str);
	str = (char *)(ft_lword_search((t_lword *)str, to_find));
	i = 0;
	while (i < sizeof(t_lword))
	{
		if (!str[i] || str[i] == to_find)
			return (str + i);
		i++;
	}
	return (str);
}

// _Pragma("GCC diagnostic pop")
