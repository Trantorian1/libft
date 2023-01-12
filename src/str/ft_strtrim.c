/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:04:15 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:59:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtrim.h"

#include <stdbool.h>
#include <stddef.h>
#include "ft_stralloc.h"

/*
 * @brief Determines if a character should be trimmed.
 *
 * @param c (char): the character to check.
 *
 * @return (bool): true if [c] should be trimmed, false otherwise.
 */
static bool	ft_is_trim(char c, const char *trim_set)
{
	while (*trim_set)
		if (*trim_set++ == c)
			return (true);
	return (false);
}

/*
 * @brief Determines the size of a string after all characters in [trim_set]
 * 	have been removed.
 *
 * @param trim_str (t_str): pointer to the first non-trimmable character in the
 * 	string to trim..
 * @param trim_set (t_str): set of a ll characters to trim.
 *
 * @return (size_t): size of [trim_str] after all trimmable charcters have been
 * 	removed.
 */
static size_t	ft_strtrim_size(const char *trim_str, const char *trim_set)
{
	size_t	trim_size;

	trim_size = 0;
	while (*trim_str++)
		trim_size++;
	if (!trim_size)
		return (0);
	trim_str -= 2;
	while (ft_is_trim(*trim_str--, trim_set))
		trim_size--;
	return (trim_size);
}

/*
 * @brief Trims off any character in [trim_set] from the start and the end of
 * 	[to_trim]. Characters wchich are in [trim_set] but not at the start or the
 * 	end of [to_trim] are ignored.
 *
 * @param to_trim (t_str): string to trim.
 * @param trim_set (t_str): set of characters to trim.
 *
 * @return (char *): Trimmed version of [to_trim], without any characters from
 * 	[trim_set] at the start or the end.
 */
char	*ft_strtrim(const char *to_trim, const char *trim_set)
{
	char	*str_trim;
	char	*trim_cpy;
	size_t	trim_size;

	if (!to_trim || !trim_set)
		return (NULL);
	while (ft_is_trim(*to_trim, trim_set))
		to_trim++;
	trim_size = ft_strtrim_size(to_trim, trim_set);
	str_trim = ft_stralloc(trim_size);
	trim_cpy = str_trim;
	if (!str_trim)
		return (NULL);
	while (trim_size--)
		*str_trim++ = *to_trim++;
	return (trim_cpy);
}
