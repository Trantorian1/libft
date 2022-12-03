/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quickfind_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:08 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/03 16:51:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdbool.h>

static void	ft_invertmagic(t_allmagic *allmagic, char *to_find)
{
	size_t	i;

	i = 0;
	while (to_find[i])
	{
		allmagic->crmagic[i] = ~allmagic->crmagic[i];
		i++;
	}
}

/**
 * @brief Generates the longwords used in bitwise operations to find the bytes
 * 	contained in [to_find].
 *
 * @param to_find (char *): the bytes to search for.
 *
 * @return (t_allmagic): structure of longwords used to find the characters in
 * 	[to_find].
 * @see ft_bytesearch_all(3)
 */
static t_allmagic	ft_allmagic(char *to_find)
{
	t_allmagic	allmagic;
	size_t		i;
	size_t		j;

	allmagic.himagic = 0x01L;
	allmagic.lomagic = 0x80L;
	allmagic.crmagic = malloc(ft_strlen(to_find) * sizeof(*allmagic.crmagic));
	i = 1;
	j = -1;
	while (to_find[++j])
		allmagic.crmagic[j] = (t_lword) to_find[j];
	while (i < sizeof(t_lword))
	{
		allmagic.lomagic |= allmagic.lomagic << i * 8;
		allmagic.himagic |= allmagic.himagic << i * 8;
		j = -1;
		while (to_find[++j])
			allmagic.crmagic[j] |= allmagic.crmagic[j] << i * 8;
		i *= 2;
	}
	ft_invertmagic(&allmagic, to_find);
	return (allmagic);
}

/**
 * @brief Searches for a series of bytes in a longword [lword] using bitwise
 * 	operations to speed up the search. Operations are the same as used in 
 * 	ft_quickfind(2), but applied to all the bytes in [to_find].
 *
 * @param lword (t_longword): the longword to search.
 * @param allmagic (t_allmagic): structure of longwords used to search for the
 * 	bytes in [to_find].
 * @param to_find (char *): the bytes we are looking for.
 *
 * @return (bool): true if the bytes we are looking for is POTENTIALLY located
 * 	in [lword], false if there is no probability that the bytes we are loking
 * 	for is in [lword].
 */
static bool	ft_bytesearch_all(t_lword lword, t_allmagic allmagic, char *to_find)
{
	size_t	i;
	t_lword	lword_cpy;

	i = 0;
	while (to_find[i])
	{
		lword_cpy = lword & allmagic.crmagic[i];
		if ((lword_cpy - allmagic.lomagic) & ~lword_cpy & allmagic.himagic)
			return (true);
	}
	return (false);
}

/**
 * @brief Handles searching for the bytes in [to_find] in longword [lword].
 *
 * @param lword (t_longword *): longword pointer to the string being searched in
 * 	ft_quickfind_all.
 * @param allmagic (t_allmagic): structure of longwords used to search for the
 * 	bytes in [to_find].
 * @param to_find (char *): the characters we are looking for.
 *
 * @return (char *): pointer to the first byte to match a character in [to_find]
 * or the end of the string pointed to by [lword] if no character in [to_find
 * was found.
 */
static char	*ft_longword_search_all(t_lword *lword, t_allmagic allmagic,
		char *to_find)
{
	char	*c;
	size_t	i;

	while (true)
	{
		if (!ft_bytesearch_all(*lword++, allmagic, to_find))
			continue ;
		c = (char *)(lword - 1);
		i = 0;
		while (i < sizeof(t_lword))
		{
			if (*ft_quickfind(to_find, c[i]) == c[i])
				return (c + i);
			i++;
		}
	}
}

/**
 * @brief Rapidly searches for any character in [to_find] in a string [str]. \
 * 	Takes advantage of longwords to compare as many bytes as possible. Support
 * 	any c longword implementation.
 *
 * 	Searching is done by first aligning [str] to the size of a longword in the
 * 	current C implementation and then searching for characters in [to_find] one
 * 	longword at a time instead of one byte at a time. Since c standard defines
 * 	long as containing at least 32 bits, or 4 bytes, this approach is at least
 * 	4x as fast as standard linear search. On implementations which support 64bit
 * 	or more longwords, this increase is even more noticeable.
 *
 * @param str (char *): the string to search.
 * @param to_find (char *): the characters to find, considered as unsigned
 *	chars.
 *
 * @return (char *): pointer to the first occurenceof character in [str] to
 * 	match a character in [to_find], or to the terminating null-byte at the end 
 * 	of [str] if no character in [to_find] was found.
 */
char	*ft_quickfind_all(char *str, char *to_find)
{
	size_t		i;
	t_allmagic	allmagic;
	t_lword		*lword;

	i = 0;
	while ((t_lword)(str + i * sizeof(*str)) & (sizeof(t_lword) - 1))
	{
		if (*ft_quickfind(to_find, str[i]) == str[i])
			return (str + i);
		i++;
	}
	allmagic = ft_allmagic(to_find);
	lword = (t_lword *)(str + i);
	return (ft_longword_search_all(lword, allmagic, to_find));
}
